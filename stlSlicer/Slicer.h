//
//  Slicer.h
//  stlSlicer
//
//  Created by Rodrigo Habib Gregori on 04/05/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include "Mesh.h"
#include "Solid.h"

using namespace std;

class Slicer
{
protected:
    float sliceThickness;
    int segmentTime;
    int sliceTime;
    bool testSliceThickness;
    
    virtual Slice getSlice(unordered_map<string, vector<string> > segments);
    
public:
    Slicer();
    virtual ~Slicer() {}
    
    bool getTestSliceThickness(void) const;
    void setTestSliceThickness(const bool bSt);
    float getSliceThickness(void) const;
    void setSliceThickness(const float st);
    void setSegmentTime(const int sTime);
    void incSegmentTime(const int sTime);
    int getSegmentTime(void) const;
    void setSliceTime(const int sTime);
    void incSliceTime(const int sTime);
    int getSliceTime(void) const;
    
    virtual Solid sliceMesh(Mesh *m) = 0;
};

