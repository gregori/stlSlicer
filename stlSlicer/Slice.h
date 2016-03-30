//
//  Slice.h
//  geometries
//
//  Created by Rodrigo Habib Gregori on 30/04/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#pragma once

#include "Geometry.h"
#include "Contour.h"
#include <vector>


using namespace std;

class Slice : public Geometry
{
private:
    vector<Contour> contours;
    
public:
    virtual ~Slice();
    void pushBack(const Contour c);
    Contour getContour(const int index);
    int getSize();
};

