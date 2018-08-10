#include "match.hpp"
#include <math.h>
using namespace sf;
using namespace std;



#include <iostream>
Circle::Circle(int xx, int yy,int nn){

    x = xx;
    y = yy;
    n = nn;
    int scl = rand()%50;
    float sclf = (scl+50)/100.0;
    cout << sclf<<endl;
    w*= sclf;
    h*= sclf;
    r = w/2;
    cx = x+r;
    cy = y+r;

    c = new Color(rand()%255,rand()%255,rand()%255);
    t = new Texture;
    t->loadFromFile("img/circle.png");
    s = new Sprite(*t);
    s->setScale(sclf,sclf);
    s->setPosition(x,y);

}
Circle::~Circle(){
    delete s;
    delete t;
    delete c;
}

void Circle::draw(RenderWindow& window){
    s->setColor(*c);
    if(hidden){
        s->setColor(Color(0,0,0,0));
    }

    window.draw(*s);
}

bool Circle::check_mouse(RenderWindow& window){
    Vector2i pos = Mouse::getPosition(window);
    cout << r <<" "<<sqrt(pow(pos.x-cx,2)+pow(pos.y-cy,2))<<" "<<cx<<" "<<cy <<endl;
    return sqrt(pow(pos.x-cx,2)+pow(pos.y-cy,2)) <= r;

}

void Circle::hide(){

    hidden = true;
}

