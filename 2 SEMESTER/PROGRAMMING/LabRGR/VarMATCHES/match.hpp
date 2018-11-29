#pragma once

#include "SFML/Graphics.hpp"


class Match{

public:
    int x,y,w=12,h=100,hidex,hidey;
    bool hidden = false, in_animation = false;
    sf::Sprite* s;
    sf::Texture* t;
    Match(int,int);
    ~Match();

    void draw(sf::RenderWindow&);
    bool check_mouse(sf::RenderWindow&);
    void hide(int,int);

};

