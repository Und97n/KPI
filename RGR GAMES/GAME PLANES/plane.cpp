#include "plane.hpp"


using namespace sf;
int getSign(float f){
    if(f > 0) return 1;
    else return -1;
}

Plane::Plane(Texture& t, RenderWindow& win, float d){
    line = 0;
    pos = -50;
    speed = 6*d;
    window = &win;
    s = new Sprite(t);
    s->setTextureRect(IntRect(0,0,w,h));
    s->setOrigin(w/2.0,h/2.0);
    s->setScale(0.8,0.8);
}

IntRect Plane::getRect(){
        float lw = w*0.8;
        float lh = h*0.8;
        return IntRect(pos-lw/2,(LINES_START_P+PIXELS_PER_LINE*line)-lh/2,lw,lh);
}

Plane::~Plane(){
    delete s;

}

void Plane::update(float factor){
    if(!dead){
        pos+=speed*factor;
    }
    if((pos < -50) || pos > W+50){

        speed = -speed;
        s->setScale(0.8*getSign(speed),0.8);
        line++;
    }
}

bool Plane::isDone(){

    return line==4 && abs(pos-W/2) < 20;

}

void Plane::die(){
    dead = true;

}

void Plane::draw(){

    s->setPosition(pos,LINES_START_P+PIXELS_PER_LINE*line);
    if(!dead){
        window->draw(*s);
    }
}
