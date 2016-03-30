//
//  Point.cpp
//  geometries
//
//  Created by Rodrigo Habib Gregori on 29/04/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#include "Point.h"
#include <cmath>
#include <vector>
#include <sstream>
#include <iomanip>

Point::Point(float _x, float _y, float _z)
{
    x = _x; y = _y; z = _z;
}

Point::Point(string label)
{
    std::istringstream ss( label );
    
    std::string coord;
    std::getline( ss, coord, '|' );
    x = atof(coord.c_str());
    std::getline( ss, coord, '|' );
    y = atof(coord.c_str());
    std::getline( ss, coord, '|' );
    z = atof(coord.c_str());
}

float Point::dotProduct(const Point &p) const
{
    return x * p.x + y * p.y + z * p.z;
}

void Point::transform(const glm::mat4 &mat)
{
    glm::vec4 v = glm::vec4(x, y, z, 1.0f);
    glm::vec4 vt;
    
    vt = mat * v;
    x = vt.x;
    y = vt.y;
    z = vt.z;
}

Point& Point::operator-=(const Point &p)
{
    x -= p.x; y -= p.y; z -= p.z;
    return *this;
}

Point Point::operator-(const Point &p)
{
    return Point(x - p.x, y - p.y, z - p.z);
}

Point Point::operator+(const Point &p)
{
    return Point(x + p.x, y + p.y, z + p.z);
}

Point Point::operator/(float a)
{
    return Point(x/a, y/a, z/a);
}

Point Point::operator*(float a)
{
    return Point(x*a, y*a, z*a);
}

float Point::normalize()
{
    return sqrt(x*x + y*y + z*z);
}

string Point::getLabel()
{
    std::stringstream ss;
    ss << std::setprecision(6) << x << "|" << std::setprecision(6) << y
    << "|" << std::setprecision(6) << z;
    return ss.str();
}

