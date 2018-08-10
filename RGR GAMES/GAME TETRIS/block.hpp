#pragma once


class Grid;
#include "grid.hpp"


using namespace std;
using namespace sf;

//Цвета для каждого типа фигуры
const Color colors[]{
    Color::Cyan,
    Color::Blue,
    Color::White,
    Color::Yellow,
    Color::Green,
    Color::Magenta,
    Color::Red
};


class Block{
public:
    int x,y;//Позиция фигуры на сетке
    int size;//Размер матрицы фигуры(может быть 3 или 4, матрица всегда квадратная)
    int** matrix;//Указатель на матрицу фигуры
    Grid* parent;//Указатель на игровое поле
    int color;//Цвет фигуры

    Block(int,Grid*);
    ~Block();

    void rotateLeft();//Метод поворота фигуры

};
