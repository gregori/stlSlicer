//
//  Rect.h
//  geometries
//
//  Created by Rodrigo Habib Gregori on 30/04/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#pragma once

#include "Geometry.h"
#include "Point.h"
#include <vector>

class Rect : public Geometry
{
private:
    std::vector<Point> points;
    
public:
    Rect();
    Rect(Point p1, Point p2);
    void pushBack(const Point p);
    Point getPoint(const int index);
    int size();
    virtual ~Rect();
};

