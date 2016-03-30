//
//  Contour.h
//  geometries
//
//  Created by Rodrigo Habib Gregori on 30/04/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#pragma once

#include "Geometry.h"
#include "Rect.h"
#include <vector>

class Contour : public Geometry
{
private:
    std::vector<Rect> segments;
    
public:
    Contour();
    virtual ~Contour();
    
    void pushBack(const Rect r);
    Rect getRect(const int index);
    int getSize();
};

