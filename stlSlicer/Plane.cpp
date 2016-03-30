//
//  Plane.cpp
//  geometries
//
//  Created by Rodrigo Habib Gregori on 29/04/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#include "Plane.h"

Plane::Plane()
{
    distance = 0;
}

Plane::~Plane()
{
}

float Plane::getDistance() const
{
    return distance;
}

float Plane::distanceToPoint(const Point &p) const
{
    return p.dotProduct(normal) - distance;
}

void Plane::setNormal(Point n)
{
    normal = n;
}

void Plane::setDistance(const float d)
{
    distance = d;
}
