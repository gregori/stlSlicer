//
//  Point.h
//  geometries
//
//  Created by Rodrigo Habib Gregori on 29/04/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#pragma once

#include "Geometry.h"
#include <string>

using namespace std;

class Point : public Geometry
{
public:
    float x, y, z;
    Point( float _x = 0, float _y = 0, float _z = 0);
    Point(string label);
    virtual ~Point() {}
    float dotProduct(const Point &p) const;
    void transform(const glm::mat4 &mat);
    Point& operator -=(const Point &p);
    Point operator-(const Point &p);
    Point operator+(const Point &p);
    Point operator/(float a);
    Point operator*(float a);
    float normalize();
    string getLabel();
};

//Point operator-(Point &a, Point &b) {return Point(a.x-b.x, a.y-b.y, a.z-b.z); }
//Point operator+(Point &a, Point &b) {return Point(a.x+b.x, a.y+b.y, a.z+b.z); }