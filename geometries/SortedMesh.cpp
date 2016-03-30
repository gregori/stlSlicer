//
//  SortedMesh.cpp
//  geometries
//
//  Created by Rodrigo Habib Gregori on 04/05/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#include "SortedMesh.h"

SortedMesh::SortedMEsh()
{
    Mesh::Mesh();
}

SortedMesh::~SortedMesh()
{
}

int SortedMesh::getSize() const
{
    returm triangleSet.size();
}

void SortedMesh::pushBack(const Triangle &t)
{
    triangleSet.insert(*t);
    Mesh::pushBack(*t);
}

tSet& SortedMesh::getMesh()
{
    return triangleSet;
}
