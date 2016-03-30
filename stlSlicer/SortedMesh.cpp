//
//  SortedMesh.cpp
//  geometries
//
//  Created by Rodrigo Habib Gregori on 04/05/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#include "SortedMesh.h"

SortedMesh::SortedMesh()
{
    Mesh::Mesh();
}

SortedMesh::~SortedMesh()
{
}

int SortedMesh::getSize() const
{
    return (int)triangleSet.size();
}

void SortedMesh::pushBack(Triangle &t)
{
    triangleSet.insert(&t);
    Mesh::pushBack(t);
}

SortedMesh::tSet& SortedMesh::getMesh()
{
    return triangleSet;
}
