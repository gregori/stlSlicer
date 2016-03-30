//
//  SimpleSlicer.cpp
//  stlSlicer
//
//  Created by Rodrigo Habib Gregori on 04/05/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#include "SimpleSlicer.h"
#include "Timer.h"
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

Solid SimpleSlicer::sliceMesh(Mesh *m)
{
    int iniTime, endTime;
    
    iniTime = Timer::getTimeMs();
    
    Solid s;
    
    unordered_map<string, vector<string> > segments;
    
    Plane plane;
    plane.setNormal(Point(0,0,1));
    Point aabb = m->meshAABBSize();
    int numSlices = 1+(int)(aabb.z/sliceThickness);
    
    vector<Triangle*> tList = m->mesh;
    float z0 = m->getBottomLeftVertex().z;
    
    for (int i = 0; i < numSlices; ++i)
    {
        plane.setDistance(z0+(float)i*sliceThickness);
        for (int j = 0; j < tList.size(); ++i)
        {
            Triangle *t = tList[j];
            Rect r;
            if (0 == t->intersectPlane(plane, r))
            {
                Point p1 = r.getPoint(0);
                Point p2 = r.getPoint(1);
                
                string label1 = p1.getLabel();
                string label2 = p2.getLabel();
                
                if (segments.find(label1) == segments.end())
                {
                    vector<string> points;
                    segments[label1] = points;
                }
                segments[label1].push_back(label2);
                
                if (segments.find(label2) == segments.end())
                {
                    vector<string> points;
                    segments[label2] = points;
                }
                segments[label2].push_back(label1);
            }
                
        }
    }
    endTime = Timer::getTimeMs();
    
    this->incSliceTime(endTime - iniTime);

    
    if (!segments.empty())
        s.pushBack(getSlice(segments));
      
    return s;
}
