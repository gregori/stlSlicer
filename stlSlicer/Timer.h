//
//  Timer.h
//  stlSlicer
//
//  Created by Rodrigo Habib Gregori on 04/05/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#pragma once

#ifdef WIN32
#include <Windows.h>
#else
#include <sys/time.h>
#include <ctime>
#endif

class Timer
{
public:
    Timer();
    ~Timer();
    static int getTimeMs();
};

