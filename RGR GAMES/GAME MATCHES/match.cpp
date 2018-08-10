#include "match.hpp"

using namespace sf;
using namespace std;




Match::Match(int xx, int yy){

    x = xx;
    y = yy;

    t = new Texture;
    t->loadFromFile("img/match.png");
    s = new Sprite(*t);
    s->setPosition(x,y);
}
Match::~Match(){
    delete s;
}

void Match::draw(RenderWindow& window){

    if(in_animation){
        if(x<hidex) x++;
        if(x>hidex) x--;
        if(y<hidey) y++;
        if(y>hidey) y--;
        s->setPosition(x,y);
        if(x==hidex&&y==hidey) in_animation = false;
    }

    if(hidden){
        s->setColor(Color::White);
    }
    window.draw(*s);

}

bool Match::check_mouse(RenderWindow& window){
    return IntRect(x,y,w,h).contains(Mouse::getPosition(window)) && !hidden;

}

void Match::hide(int i, int player){

    int start = (player==0)?15:485;
    hidex = 50+15*(i%20);
    hidey = start+15*(i/20);
    in_animation = true;



    hidden = true;
}

