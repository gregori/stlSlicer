//
//  Mesh.h
//  geometries
//
//  Created by Rodrigo Habib Gregori on 29/04/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#pragma once

#include "Geometry.h"
#include "Triangle.h"
#include "Point.h"


class Mesh : public Geometry
{
private:
    //std::vector<Triangle*> mesh;
    Point bottomLeftVertex, upperRightVertex;
    
public:
    std::vector<Triangle*> mesh;
    virtual ~Mesh() {}
    Mesh();
    void normalize();
    virtual void pushBack(Triangle &t);
    Point meshAABBSize();
    std::vector<Triangle*> getMesh();
    Point getBottomLeftVertex();
    Point getUpperRightVertex();
    int transform(const glm::mat4 &mat);
    virtual int getSize() const;
};
