//
//  Plane.h
//  geometries
//
//  Created by Rodrigo Habib Gregori on 29/04/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#pragma once

#include "Geometry.h"
#include "Point.h"

class Plane : public Geometry
{
private:
    Point normal;
    float distance;
    
public:
    Plane();
    virtual ~Plane();
    float getDistance() const;
    float distanceToPoint(const Point &p) const;
    void setNormal(Point n);
    void setDistance(const float d);
};

