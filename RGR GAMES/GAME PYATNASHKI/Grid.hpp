
#pragma once

#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

//Класс который представляет игровое поле
class Grid{

public:
    int sizex,sizey,sizex_pixel,sizey_pixel;//Размеры сетки в клетках и пикселях

    int x,y, turns; // Позиция сетки на карте и количество ходов
    int** grid;// Указатель на двмерный массив, в котором хранятся данные игрового поля
    Font *font;// Указатель на шрифт для вывода номеров и текста


    RenderWindow* window;// Указатель на окно для рисованияч

    Grid(RenderWindow* a);//Конструктор принимает окно для рисования
    ~Grid();//Дестрктор

    void draw(void);//Метод который рисует игровое поле


    bool isendgame();//Мето для проверки того закончена ли игра
    bool findmoves(int&, int&);//Метод для поиска возможных ходов для клетки, принимает координаты клетки
    void click();// Метод для обработки клика по полю

};

