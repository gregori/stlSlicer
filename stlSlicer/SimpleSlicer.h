//
//  SimpleSlicer.h
//  stlSlicer
//
//  Created by Rodrigo Habib Gregori on 04/05/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#pragma once
#include "Slicer.h"
#include "Mesh.h"
#include "Solid.h"

class SimpleSlicer : public Slicer
{
public:
    virtual ~SimpleSlicer() {}
    Solid sliceMesh(Mesh *m);
};

