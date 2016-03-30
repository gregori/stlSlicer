//
//  SortedSlicer.cpp
//  stlSlicer
//
//  Created by Rodrigo Habib Gregori on 04/05/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#include "SortedSlicer.h"
#include "SortedMesh.h"
#include "Timer.h"
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

SortedSlicer::SortedSlicer()
{
}

SortedSlicer::~SortedSlicer()
{
}


Solid SortedSlicer::sliceMesh(Mesh *m)
{
    int iniTime, endTime;
    int indexIni, indexProx, index;
    float z;
    std::vector<float> zVector;
    
    iniTime = Timer::getTimeMs();
    
    Solid s;
    
    unordered_map<int, unordered_map<std::string, vector<string> > > segments;
    
    Plane plane;
    plane.setNormal(Point(0,0,1));
    Point aabb = m->meshAABBSize();
    
    SortedMesh *sm = static_cast<SortedMesh*>(m);
    SortedMesh::tSet triangleSet = sm->getMesh();

    index = indexIni = indexProx = 0;
    
    float z0 = m->getBottomLeftVertex().z;
    
    for (float i = z0; i < m->getUpperRightVertex().z; i += sliceThickness)
    {
        zVector.push_back(i);
    }
    
    SortedMesh::tSet::iterator itProx;
    
    for (SortedMesh::tSet::iterator it = triangleSet.begin(),itEnd = triangleSet.end(); it != itEnd; ++it)
    {
        itProx = next(it,1);
        
        Triangle *t = *it;
        Triangle *tProx = *itProx;
        
        z = zVector[index];
        
        while (z < t->getZMax() && index < zVector.size())
        {
            //m->incSliceCounter();
            Rect r;
            plane.setDistance(z);
            
            if (0 == t->intersectPlane(plane, r))
            {
                if (!indexIni)
                    indexIni = index;
                
                //m->incIfCounter();
                Point p1 = r.getPoint(0);
                Point p2 = r.getPoint(1);
                
                string label1 = p1.getLabel();
                string label2 = p2.getLabel();
                
                if ((segments[index]).find(label1) == (segments[index]).end())
                {
                    vector<string> points;
                    segments[index][label1] = points;
                }
                (segments[index][label1]).push_back(label2);
                
                if ((segments[index]).find(label2) == (segments[index]).end())
                {
                    vector<string> points;
                    segments[index][label2] = points;
                }
                
                (segments[index][label2]).push_back(label1);
            }
            
            if (!indexProx && itProx != itEnd && !tProx->intersectPlane(plane, r))
                indexProx = index;
            
            z = zVector[++index];
        }
        
        if (indexProx)
            indexIni = indexProx;
        
        indexProx = 0;
    }
    
    endTime = Timer::getTimeMs();
    
    this->incSliceTime(endTime - iniTime);
    for (unordered_map<int, unordered_map<string, vector<string> > >::iterator it = segments.begin();
         it != segments.end(); ++it)
        
        if (!(it->second).empty())
            s.pushBack(getSlice(it->second));
    
    
    return s;
}