//
//  FacetComparer.cpp
//  geometries
//
//  Created by Rodrigo Habib Gregori on 04/05/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#include "FacetComparer.h"

bool FacetComparer::operator() (const Triangle *t1, const Triangle *t2) const
{
    if (t1->getZMin() == t2->getZMin()) {
        return t1->getZMax() < t2->getZMax();
    } else {
        return t1->getZMin() < t2->getZMin();
    }
}
