#pragma once
#include <iostream>

class Material{

    char* name, *conductance;
    int density;
public:
    Material();
    Material(char*, int, char*);
    Material(const Material&);

    ~Material();

    void setValues(char*, int, char*);
    char* getName();
    int getDensity();
    char* getConductance();



};
