//
//  Geometry.h
//  geometries
//
//  Created by Rodrigo Habib Gregori on 29/04/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#pragma once

#define GLM_FORCE_RADIANS

#include "../glm/glm/glm.hpp"
#include "../glm/glm/gtc/matrix_transform.hpp"
#include "../glm/glm/gtc/type_ptr.hpp"

#define DEG_TO_RAD(x) (x*0.0174532925199f)

class Geometry
{
public:
    virtual ~Geometry() {}
};

