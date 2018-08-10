#include "Material.hpp"


using namespace std;

Material::Material(char* n, int d, char* cond){
    cout << "Конструктор з параметрами" << endl;
    name = n;
    density = d;
    conductance = cond;
}

Material::Material(){
    cout <<  " Конструктор без параметрів"<< endl;
    name = "Metal";
    density = 5;
    conductance = "Great";
}

Material::Material(const Material& m){
    cout << "Конструктор копыювання" << endl;
    name = m.name;
    density = m.density;
    conductance = m.conductance;
}

Material::~Material(){
    cout << "Деструктор " << name << endl;

}

void Material::setValues(char* n, int d, char* cond){
    name = n;
    density = d;
    conductance = cond;

}

int Material::getDensity(){
    return density;
}

char* Material::getName(){
    return name;
}

char* Material::getConductance(){
    return conductance;
}

