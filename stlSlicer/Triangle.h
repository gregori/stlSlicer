//
//  Triangle.h
//  geometries
//
//  Created by Rodrigo Habib Gregori on 29/04/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#pragma once

#include "Geometry.h"
#include "Point.h"
#include "Rect.h"
#include "Plane.h"

class Triangle : public Geometry
{
private:
    Point normal;
    float zMin, zMax;
public:
    Point v[3];
    Triangle(Point n, Point v1, Point v2, Point v3);
    virtual ~Triangle();
    void transform(const glm::mat4 &mat);
    int intersectPlane(const Plane &plane, Rect &r) const;
    Triangle& operator-=(const Point &pt);
    float getZMin() const;
    float getZMax() const;
    void setZMin(const float z);
    void setZMax(const float z);
};

