//
//  Rect.cpp
//  geometries
//
//  Created by Rodrigo Habib Gregori on 30/04/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#include "Rect.h"

Rect::Rect()
{
    
}

Rect::~Rect()
{
}

Rect::Rect(Point p1, Point p2)
{
    points.push_back(p1);
    points.push_back(p2);
}

void Rect::pushBack(const Point p)
{
    points.push_back(p);
}

Point Rect::getPoint(const int index)
{
    return points.at(index);
}

int Rect::size()
{
    return (int)points.size();
}
