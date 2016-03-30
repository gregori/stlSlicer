//
//  Solid.cpp
//  geometries
//
//  Created by Rodrigo Habib Gregori on 30/04/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#include "Solid.h"

Solid::~Solid()
{
}

void Solid::pushBack(const Slice s)
{
    slices.push_back(s);
}

Slice Solid::getSlice(const int index) const
{
    return slices.at(index);
}

int Solid::getSize() const
{
    return slices.size();
}