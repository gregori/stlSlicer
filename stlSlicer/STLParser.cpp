//==============================================================================
// STLParser.cpp
// Copyright 2014 Rodrigo Habib Gregori. All rights reserved.
//==============================================================================

#include "STLParser.h"
#include <regex>
using namespace std;

STLParser::STLParser(string fn)
{
    fileName = fn;
}


STLParser::~STLParser(void)
{
}

void STLParser::setFileName(string f)
{
    fileName = f;
}

string STLParser::getFileName(void) const
{
    return fileName;
}

void STLParser::setSTLMesh(Mesh m)
{
    stlMesh = m;
}

Mesh STLParser::getSTLMesh(void) const
{
    return stlMesh;
}

bool STLParser::checkSTLFile(string fileName) const
{
    string fn = fileName; // STL filename
    
    ifstream input;
    
    input.open(fn.c_str());  // trying to read the file
    
    if (!input)
    {
        throw "Could not open STL file!";
    }
    
    // TODO: Better checking
    
    input.close();
    
    return true;
}

bool STLParser::isASCIISTLFile(string fileName)
{
    string line1, line2;
    ifstream input;
    regex solid("^solid");
    regex facet("facet");
    smatch m1, m2;
    bool found1, found2;
    
    input.open(fileName.c_str());
    
    getline(input, line1);
    getline(input, line2);
    
    
    found1 = regex_search(line1, m1, solid);
    found2 = regex_search(line2, m2, facet);
    
    return (found1 && found2);
}

int STLParser::parseASCIIFile(string fileName, Mesh *m)
{
    ifstream in(fileName);
    if (!in.good()) return 1;
    //char title[80];
    string title;
    string s0, s1; // dummy strings - the keywords of the STL file
    float n1, n2, n3, f1, f2, f3, f4, f5, f6, f7, f8, f9; // float coordinates for the normal and vertices
    
    //in.read(title, 80); // read the STL title
    in >> title >> s0;
    while (!in.eof())
    {
        in >> s0;   // facet || endsolid
        if ("facet" == s0)
        {
            in >> s1 >> n1 >> n2 >> n3;   // normal x y z
            in >> s0 >> s1;    // outer loop
            in >> s0 >> f1 >> f2 >> f3;   // vertex x y z
            in >> s0 >> f4 >> f5 >> f6;   // vertex x y z
            in >> s0 >> f7 >> f8 >> f9;   // vertex x y z
            in >> s0;       // endloop
            in >> s0;       // endfacet
            
            // Create a new Triangle with the normal and Vertices values
            Triangle t(Point(n1, n2, n3), Point(f1, f2, f3), Point(f4, f5, f6), Point(f7, f8, f9));
            m->pushBack(t);
        }
        else if ("endsolid" == s0)
            break;
    }
    in.close();
    
    return 0;
}

int STLParser::parseBinaryFile(string fileName, Mesh *m)
{
    char header[80];
    char* bCount;
    float v[12]; // coordinates: normal=3 + vertices=3 * 3 = 12
    long triangleCount = 0;
    
    string fn = fileName;
    ifstream in(fn.c_str(), ios::in|ios::binary);
    
    if (!in.good()) return 1;
    
    in.read(header, 80);
    in.read((char*) &triangleCount, 4);
    
    for (int i = 0; i < triangleCount; ++i)
    {
        for (int j = 0; j < 12; ++j)
            in.read((char*) &v[j], 4);
        
        bCount = new char[2];
        in.read(bCount, 2); // spacer between faces
        
        Triangle t(Point(v[0], v[1], v[2]), Point(v[3], v[4], v[5]),
                   Point(v[6], v[7], v[8]), Point(v[9], v[10], v[11]));
        
        m->pushBack(t);
    }
    
    in.close();
    return 0;
}

Mesh* STLParser::parseFile(string fileName)
{
    Mesh *m = new Mesh();
    int retVal;
    if (isASCIISTLFile(fileName))
        retVal = parseASCIIFile(fileName, m);
    else
        retVal = parseBinaryFile(fileName, m);
    
    if (!retVal) m->normalize();
    
    return m;
}

