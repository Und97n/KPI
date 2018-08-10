#include "bullet.hpp"


using namespace sf;

Bullet::Bullet(float xx, float yy, RenderWindow& win){
    window = &win;
    radius = 0;
    x = xx;
    y = yy;
    rec = new RectangleShape(Vector2f(4,4));
    rec->setFillColor(Color::Red);
    rec->setOrigin(2,2);

}


Bullet::~Bullet(){
    delete rec;
}

int Bullet::colcheck(vector<Plane*> planes){
    if(is_explosion) return -1;
    for(int i =0;i<planes.size();i++){
        if(planes[i]->getRect().contains(Vector2i(x,y))){
            planes[i]->die();
            x = planes[i]->pos;
            y = LINES_START_P+PIXELS_PER_LINE*planes[i]->line;
            is_explosion = true;
            return i;
        }


    }
    return -1;

}


void Bullet::draw(){
    if(is_explosion){
        CircleShape a(radius);
        a.setFillColor(Color::Yellow);
        a.setOrigin(radius,radius);
        a.setPosition(x,y);

        window->draw(a);
    }
    else{
        rec->setPosition(x,y);
        window->draw(*rec);
    }
}

bool Bullet::update(float factor){
    if(is_explosion){
        radius++;
        if(radius>=30){
            return true;
        }
        return false;
    }else{
        y-= speed*factor;
        if(y<0){
            return true;
        }
        return false;
        }
}
