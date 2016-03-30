//
//  FacetComparer.h
//  geometries
//
//  Created by Rodrigo Habib Gregori on 04/05/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#pragma once
#include "Triangle.h"

class FacetComparer
{
public:
    bool operator() (const Triangle *t1, const Triangle *t2) const;
    virtual ~FacetComparer() {}
};

