//
//  Mesh.cpp
//  geometries
//
//  Created by Rodrigo Habib Gregori on 29/04/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#include "Mesh.h"
#include <cfloat>

Mesh::Mesh()
{
    bottomLeftVertex.x = FLT_MAX;
    bottomLeftVertex.y = FLT_MAX;
    bottomLeftVertex.z = FLT_MAX;
    
    upperRightVertex.x = FLT_MIN;
    upperRightVertex.y = FLT_MIN;
    upperRightVertex.z = FLT_MIN;
}

int Mesh::getSize() const
{
    return (int)mesh.size();
}

void Mesh::normalize()
{
    Point halfBbox = (upperRightVertex - bottomLeftVertex)/2.0f;
    Point start = bottomLeftVertex + halfBbox;
    
    for (int i=0; i < mesh.size(); ++i)
    {
        Triangle *triangle = mesh[i];
        *triangle -= start;
    }
    
    bottomLeftVertex = halfBbox * -1.0f;
    upperRightVertex = halfBbox;
}



void Mesh::pushBack(Triangle &t)
{
    mesh.push_back(&t);
    for (int i=0; i<3; ++i)
    {
        if (t.v[i].x < bottomLeftVertex.x) bottomLeftVertex.x = t.v[i].x;
        if (t.v[i].y < bottomLeftVertex.y) bottomLeftVertex.y = t.v[i].y;
        if (t.v[i].z < bottomLeftVertex.z) bottomLeftVertex.z = t.v[i].z;
        if (t.v[i].x > upperRightVertex.x) upperRightVertex.x = t.v[i].x;
        if (t.v[i].y > upperRightVertex.y) upperRightVertex.y = t.v[i].y;
        if (t.v[i].z > upperRightVertex.z) upperRightVertex.z = t.v[i].z;
    }
}

Point Mesh::meshAABBSize()
{
    return Point(upperRightVertex.x - bottomLeftVertex.x, upperRightVertex.y - bottomLeftVertex.y,
                 upperRightVertex.z - bottomLeftVertex.z);
}

std::vector<Triangle*> Mesh::getMesh()
{
    return mesh;
}

Point Mesh::getBottomLeftVertex()
{
    return bottomLeftVertex;
}

Point Mesh::getUpperRightVertex()
{
    return upperRightVertex;
}

int Mesh::transform(const glm::mat4 &mat)
{
    for (int i=0; i < mesh.size(); ++i)
    {
        Triangle *t = mesh[i];
        t->transform(mat);
    }
    
    return 0;
}