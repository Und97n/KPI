#pragma once

#include "common.hpp"
#include "plane.hpp"

using namespace sf;
using namespace std;

class Bullet{
public:
    float x,y;//Позиция пули
    bool is_explosion = false;//Флаг взрывния пули
    float speed = 20;//Скорость пули
    float radius;//Радиус взрыва пулт
    RenderWindow* window;//Указатель на окно для рисования
    RectangleShape* rec;//Спрайт пули


    Bullet(float,float,RenderWindow&);
    ~Bullet();
    void draw();//Рисование пули
    bool update(float);//Логика полета пули
    int colcheck(vector<Plane*>);//Проверка столкновений с самолетами


};
