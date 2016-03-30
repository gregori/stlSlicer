//
//  Slicer.cpp
//  stlSlicer
//
//  Created by Rodrigo Habib Gregori on 04/05/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#include "Slicer.h"
#include "Timer.h"
#include "geometries.h"

Slicer::Slicer()
{
    sliceThickness = 0.152f;
}

Slice Slicer::getSlice(unordered_map<string, vector<string> > segments)
{
    int timeIni, timeEnd;
    Slice s;
    
    timeIni = Timer::getTimeMs();
    
    std::unordered_map<std::string, std::vector<std::string> >::iterator segIt;

    std::string origin, lblP1, lblP2 = "";
    
    while (!segments.empty())
    {
        Contour c;
        
        segIt = segments.begin();
        origin = lblP1 = segIt->first;
        std::vector<std::string> pVec = segIt->second;
        lblP2 = pVec.at(0);
        
        Point p1(lblP1);
        Point p2(lblP2);
        
        Rect l(p1, p2);
        
        c.pushBack(l);
        
        segments.erase(segIt);
        
        while (segments.count(lblP2))
        {
            p1 = p2;
            lblP1 = lblP2;
            lblP2 = segments[lblP2][0] == origin ? segments[lblP2][1] : segments[lblP2][0];
            p2 = Point(lblP2);
            
            Rect l(p1, p2);
            
            c.pushBack(l);
            segments.erase(segments.find(lblP1));
            
            origin = lblP1;
        }
        
        s.pushBack(c);
    }
    
    timeEnd = Timer::getTimeMs();
    
    this->incSegmentTime(timeEnd - timeIni);
    
    return s;
}

bool Slicer::getTestSliceThickness(void) const
{
    return testSliceThickness;
}

void Slicer::setTestSliceThickness(const bool bSt)
{
    testSliceThickness = bSt;
}

float Slicer::getSliceThickness(void) const
{
    return sliceThickness;
}

void Slicer::setSliceThickness(const float st)
{
    sliceThickness = st;
}

void Slicer::setSegmentTime(const int sTime)
{
    segmentTime = sTime;
}

void Slicer::incSegmentTime(const int sTime)
{
    segmentTime += sTime;
}

int Slicer::getSegmentTime(void) const
{
    return segmentTime;
}

void Slicer::setSliceTime(const int sTime)
{
    sliceTime = sTime;
}

void Slicer::incSliceTime(const int sTime)
{
    sliceTime += sTime;
}

int Slicer::getSliceTime(void) const
{
    return sliceTime;
}

