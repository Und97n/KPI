#pragma once
#include "common.hpp"
#include <stdlib.h>

using namespace sf;

class Plane{
public:
    float line,pos;//Линия и позиция самолета
    float speed;//Скорость самолета
    int w = 100, h = 75;//Размеры самолета
    Sprite* s;//Спрайт самолета
    bool dead;//Флаг сбитости самолета
    RenderWindow* window;//Указатель на окно для рисования

    Plane(Texture&, RenderWindow&,float);
    ~Plane();

    void draw();//Метод рисования самолета
    void update(float factor);//Логика полета
    void die();//Функция сбития
    bool isDone();//Функция проверки того долетел ли самолет до цели
    IntRect getRect();//Получение позиции и размеров самолета






};
