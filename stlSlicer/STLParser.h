//==============================================================================
// STLParser.h
// Copyright 2014 Rodrigo Habib Gregori. All rights reserved.
//==============================================================================

#pragma once
#include <string>
#include <fstream>
#include "Mesh.h"

using namespace std;

class STLParser
{
private:
    string fileName;
    Mesh stlMesh;
    
    //methods
    virtual bool checkSTLFile(void) { return false; };

public:
    STLParser(const string fn="");
    virtual ~STLParser(void);
    virtual Mesh* parseFile(string fileName);
    virtual int parseASCIIFile(string fileName, Mesh *m);
    virtual int parseBinaryFile(string fileName, Mesh *m);
    void setFileName(string f);
    string getFileName(void) const;
    void setSTLMesh(Mesh m);
    Mesh getSTLMesh(void) const;
    bool isASCIISTLFile(string fileName);
    bool checkSTLFile(string fileName) const;
};

