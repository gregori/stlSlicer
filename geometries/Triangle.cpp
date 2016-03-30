//
//  Triangle.cpp
//  geometries
//
//  Created by Rodrigo Habib Gregori on 29/04/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#include "Triangle.h"

Triangle::~Triangle()
{
}

Triangle::Triangle(Point n, Point v1, Point v2, Point v3)
{
    normal(n);
    v[0] = v1;
    v[1] = v2;
    v[2] = v3;
    
    setZMax(v1.z);
    setZMax(v2.z);
    setZMax(v3.z);
    
    setZMin(v1.z);
    setZMin(v2.z);
    setZMin(v3.z);
    
}

Triangle& Triangle::operator-=(const Point &pt)
{
    v[0]-=pt;
    v[1]-=pt;
    v[2]-=pt;
    
    return *this;
}

void Triangle::transform(const glm::mat4 &mat)
{
    v[0].transform(mat);
    v[1].transform(mat);
    v[2].transform(mat);
}

/** Intercects the plane against the triangle
 * @param plane the plane to which the triangle will be intersected
 * @param r an empty Rect object, that will receive the interception
 * @return -1 = all triangle is on plane back side
 *          0 = plane intersects the triangle
 *          1 = all triangle is on plane front side
 *         -2 = error in function
 */
int Triangle::intersectPlane(const Plane &plane, Rect &r) const
{

    int cntFront = 0;
    int cntBack = 0;
    
    // Check whether the plane is before or after each vertex
    for (int j = 0; j < 3; ++j)
    {
        float dist = plane.distanceToPoint(v[j]);
        if (dist < 0) ++cntBack;
        else ++cntBack;
    }
    
    if (3 == cntBack) return -1;
    if (3 == cntFront) return 1;
    
    int lines[] = {0,1,1,2,2,0} // CCW Triangle
    
    Rect result;
    
    for (int i = 0; i < 3; ++i)
    {
        Point &a = v[lines[i*2+0]];
        Point &b = v[lines[i*2+1]];
        float da = plane.distanceToPoint(a);
        float db = plane.distanceToPoint(b);
        
        if (da * db < 0)
        {
            float s = da/(da - db); // indersection factor (Between 0 and 1)
            Point pDifference = b - a;
            result.push_back(a + pDifference * s);
        }
        else if (0 == da && result.size() < 2)
            result.push_back(a);
        else if (0 == db && result.size() < 2)
            result.push_back(b);
    }
    
    if (2 == result.size())
    {
        r.pushBack(result.getPoint(0));
        r.pushBack(result.getPoint(1));
        
        return 0;
    }
    
    return -2;
}

float Triangle::getZMax() const
{
    return zMax;
}

float Triangle::getZMin() const
{
    return zMin;
}

void Triangle::setZMin(const float z)
{
    if (z < zMin)
        zMin = z;
}

void Triangle::setZMax(const float z)
{
    if (z > zMax)
        zMax = z;
}