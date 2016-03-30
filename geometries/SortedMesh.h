//
//  SortedMesh.h
//  geometries
//
//  Created by Rodrigo Habib Gregori on 04/05/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#pragma once

#include "Mesh.h"
#include "FacetComparer.h"
#include "SortedSlicer.h"
#include <set>

class SortedMesh : public Mesh
{
private:
    typedef multiset<Triangle*, FacetComparer> tSet;
    tSet triangleSet;
    
    friend Solid SortedSlicer::sliceMesh(Mesh *m);
    
public:
    SortedMesh();
    virtual ~SortedMesh();
    tSet& getMesh();
    void pushBack(const Triangle &t);
    int getSize() const;
};

