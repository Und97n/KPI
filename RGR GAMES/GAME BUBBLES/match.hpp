#pragma once
#include <stdlib.h>
#include "SFML/Graphics.hpp"


class Circle{

public:
    int x,y,w=100,h=100,r=50,cx,cy,n;
    bool hidden = false;
    sf::Sprite* s;
    sf::Texture* t;
    sf::Color* c;
    Circle(int,int,int);
    ~Circle();

    void draw(sf::RenderWindow&);
    bool check_mouse(sf::RenderWindow&);
    void hide();

};

