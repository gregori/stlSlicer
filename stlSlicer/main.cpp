//
//  main.cpp
//  stlSlicer
//
//  Created by Rodrigo Habib Gregori on 29/04/14.
//  Copyright (c) 2014 Rodrigo Habib Gregori. All rights reserved.
//

#include <iostream>
#include <vector>
#include "geometries.h"
#include "STLParser.h"
#include "Slicer.h"
#include "SimpleSlicer.h"
#include "SortedSlicer.h"
#include "Timer.h"

#define GLM_FORCE_RADIANS

#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"
#include "glm/glm/gtc/type_ptr.hpp"

#define DEG_TO_RAD(x) (x*0.0174532925199f)
using namespace std;

static void show_usage(std::string name)
{
    std::cerr << "Usage: " << name << " <option(s)> <STLFILE>"
    << "Options:\n"
    << "\t-h,--help\t\tShow this help message\n"
    << "\t-t,--thickness <SLICE THICKNESS>\tSpecify the slice thickness (float value)\n"
    << "\t-s,--simple\tSimple Slicing\n"
    << "\t-o,--sort\tSorted Slicing"
    << std::endl;
}


void printLatex(Solid s)
{
    std::cout << "\\documentclass{article}" << std::endl;
    std::cout << "\\usepackage{tikz,tikz-3dplot}" << std::endl;
    std::cout << "\\begin{document}" << std::endl;
    std::cout << "\\begin{tikzpicture}[scale=3,cm={-1,-1,1,0,(0,0)},x=3.85mm,z=-1cm]" << std::endl;
    std::cout << std::endl;
    
    for (int i = 0; i < s.getSize(); ++i) // Slices
    {
        Slice sl = s.getSlice(i);
        for (int j = 0; j < sl.getSize(); ++j)  // Contours
        {
            Contour c = sl.getContour(j);
            
            std::cout << "\\draw ";
            
            for (int k = 0; k < c.getSize(); ++k) // Rects
            {
                Rect r = c.getRect(k);
                std::cout << "(" << r.getPoint(0).x << ", " << r.getPoint(0).y << ", "
                << r.getPoint(0).z << ") -- ";
                std::cout << "(" << r.getPoint(1).x << ", " << r.getPoint(1).y << ", "
                << r.getPoint(1).z << ") -- ";
            }
            
            std::cout << "cycle;" << std::endl;
        }
    }
    
    std::cout << "\\end{tikzpicture}" << std::endl;
    std::cout << "\\end{document}" << std::endl;
    
}

int main(int argc, const char * argv[])
{
    string fileName;
    int timeIni, timeEnd;
    float thickness;
    Slicer *sl = new SimpleSlicer();
    STLParser parser;
    Solid s;
    Mesh *mesh;
    glm::highp_fvec3 eulerAngles(0,0,0);
    
    if (argc < 2)
    {
        show_usage(argv[0]);
        return 1;
    }
    
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        if ((arg == "-h") || (arg == "--help"))
        {
            show_usage(argv[0]);
            return 0;
        }
        else if ((arg == "-t") || (arg == "--thickness"))
        {
            if (i + 1 < argc)
            { // Make sure we aren't at the end of argv!
                thickness = atof(argv[i++]); // Increment 'i' so we don't get the argument as the next argv[i].
            } else
            { // Uh-oh, there was no argument to the destination option.
                std::cerr << "--thickness option requires one argument." << std::endl;
                return 1;
            }
        }
        else if ((arg == "-s") || (arg == "--simple"))
        { // Simple Slicing
            sl = new SimpleSlicer();
            mesh = new Mesh();
        }
        else if ((arg == "-o") || (arg == "--sort"))
        { // Sorted Slicing
            sl = new SortedSlicer();
            mesh = static_cast<Mesh*>(new SortedMesh());
        }
        else
        {
            fileName = argv[i]; // The file to be sliced
        }
    }
    
    cout << "Importing File: " << fileName << "." << endl;
    
    timeIni = Timer::getTimeMs();
    parser.setFileName(fileName);
    mesh = parser.parseFile(fileName);
    
    cout << "Time: " << (timeEnd - timeIni) << " milliseconds."  << endl;
    
    // Optional Model Rotation Around COG Point using GLM Library
    glm::mat4 mat = glm::mat4(1.0f);
    //glm::detail::tquat<float> quaternion = glm::detail::tquat<float>(DEG_TO_RAD(eulerAngles)); // This glm func wants values as radians
    glm::fquat quaternion = glm::fquat(DEG_TO_RAD(eulerAngles)); // This glm func wants values as radians
    float angle = glm::angle(quaternion);
    //glm::detail::tvec3<float> axis = glm::axis(quaternion);
    glm::highp_fvec3 axis = glm::axis(quaternion);
    mat = glm::rotate(mat, angle, axis);
    mesh->transform(mat);
    
    cout << "Slicing mesh." << endl;
    cout << "Took ...";
    s = sl->sliceMesh(mesh);
    cout << sl->getSliceTime() << " for slicing and " << sl->getSegmentTime()
            << " for building contours." << endl;
    
    printLatex(s);
}
