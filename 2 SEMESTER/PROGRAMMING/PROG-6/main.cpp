#include <iostream>
#include "Material.hpp"
using namespace std;

int main()
{

    Material mat;
    Material *mat2 = new Material("Test",2,"Test2");
    Material mat3(*mat2);


    int (Material::*methodptr)();
    methodptr = &Material::getDensity;




    int d = mat3.getDensity();
    cout << "Density of mat 3 = "<<d<<endl;
    mat2->setValues("Test setter",5,"Test setter");
    d = mat2->getDensity();
    cout << "Method pointer applyed to mat3 density = "<<(mat3.*methodptr)()<<endl;
    cout << "Density of mat 2 = "<<d<<endl;


    return 0;
}
