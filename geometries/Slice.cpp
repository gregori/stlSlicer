//
//  Slice.cpp
//  geometries
//
//  Created by Rodrigo Habib Gregori on 30/04/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#include "Slice.h"

Slice::~Slice()
{
}

void Slice::pushBack(const Contour c)
{
    contours.push_back(c);
}

Contour Slice::getContour(const int index)
{
    return contours.at(index);
}

int Slice::getSize()
{
    return contours.size();
}