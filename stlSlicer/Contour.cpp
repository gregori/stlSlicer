//
//  Contour.cpp
//  geometries
//
//  Created by Rodrigo Habib Gregori on 30/04/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#include "Contour.h"

Contour::~Contour()
{
}

Contour::Contour()
{
    
}

void Contour::pushBack(const Rect r)
{
    segments.push_back(r);
}

Rect Contour::getRect(const int index)
{
    return segments.at(index);
}

int Contour::getSize()
{
    return (int)segments.size();
}
