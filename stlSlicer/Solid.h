//
//  Solid.h
//  geometries
//
//  Created by Rodrigo Habib Gregori on 30/04/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#pragma once

#include "Geometry.h"
#include "Slice.h"
#include <vector>

using namespace std;

class Solid : public Geometry
{
private:
    vector<Slice> slices;
    
public:
    virtual ~Solid();
    void pushBack(const Slice s);
    Slice getSlice(const int index) const;
    int getSize() const;
};

