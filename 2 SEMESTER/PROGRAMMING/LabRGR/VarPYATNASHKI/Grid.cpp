#include "Grid.hpp"
#include <iostream>
#include <stdlib.h>


using namespace std;
using namespace sf;
Grid::Grid(RenderWindow* a){

    turns = 0;
    srand(time(0));//Инициализация генератора случайных чисел
    window = a;
    sizex = 4;
    sizey = 4;
    sizex_pixel=sizey_pixel = 400;

    x = y = 100;

    //Загрузка шрифта
    font = new Font;
    font->loadFromFile("cour.ttf");

    //Создание двумерного массива значений клеток
    grid = new int*[4];
    for(int i=0;i<4;i++){
        grid[i] = new int[4];
    }

    //Заполнение массива случайными значениями
    // 0 - пустая клетка
    vector<int> ints = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,0,15};
    random_shuffle(ints.begin(), ints.end());//Функция перемешивания вектора
    for(int i=0;i<16;i++){
        grid[i%4][i/4] = ints[i];
        //   ^^^^^^^^^ - Превращение координат вектора в координаты матрицы
    }



}




Grid::~Grid(){
    //Освобождение памяти
    for(int i=0;i<sizey;i++){
        delete[]grid[i];
    }
    delete[]grid;


}



void Grid::draw(){
    //Размер клетки
    int hx = sizey_pixel/sizey;

    //Отрисовка сетки
    for(int i=0;i<=sizey;i++){

        int scry = y+hx*i;
        Vertex line[] = {
            Vertex(Vector2f(x,scry)),
            Vertex(Vector2f(x+sizex_pixel,scry))

        };
        window->draw(line,2,Lines);
    }
    int hy = sizex_pixel/sizex;
    for(int i=0;i<=sizex;i++){
        int scrx = x+hy*i;
        Vertex line[] = {
            Vertex(Vector2f(scrx,y)),
            Vertex(Vector2f(scrx,y+sizey_pixel))

        };
        window->draw(line,2,Lines);
    }
    //Зарисовка клеток белым цветом
    RectangleShape rect(Vector2f(hx-2,hy-2));
    rect.setFillColor(Color::White);
    //rect.setPosition(x+hx*posx,y+hy*posy);
    //window->draw(rect);
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            if(grid[i][j] != 0){
                rect.setPosition(x+hx*j,y+hy*i);
                window->draw(rect);
            }
        }
    }



    Text text;
    text.setFont(*font);
    text.setCharacterSize(hx/2);
    //Вывод номеров клеток

    for(int i=0;i<sizey;i++){
        for(int j=0;j<sizex;j++){

                text.setColor(Color::Black);


            if(grid[i][j]!=0){
                text.setString(to_string(grid[i][j]));
                text.setPosition(5+x+hx*j,-5+y+hy*i);
                window->draw(text);
            }
        }
    }
    //Вывод информационного текста
    if(!this->isendgame()){
        text.setString(L"Ходов сделано: "+to_string(turns));

    }else{
        text.setString(L"Вы выйграли");
    }
    text.setColor(Color::White);
        text.setPosition(10,10);
    window->draw(text);

}


void Grid::click(){

    int h = sizey_pixel/sizey;
    Vector2i pos = Mouse::getPosition(*window);//Получение текущей позиции мыши
    int mx = (pos.x - x)/h;
    int my = (pos.y - y)/h;
    cout << my << mx << endl;
    if(my < 0 || my > 3 || mx < 0 || my > 3){
        return;
    }
    int newx = mx,newy = my;
    //Если есть доступные ходы меняем значения клеток местами
    if(findmoves(newx,newy)){
        int t = grid[newy][newx];
        grid[newy][newx] = grid[my][mx];
        grid[my][mx] = t;
        turns++;
    }

}

bool Grid::findmoves(int& mx, int& my){
    //Проверка соседних клеток на пустоту
    if(my-1>=0 && grid[my-1][mx]==0){
        my-=1;
        return true;
    }if(my+1<4 && grid[my+1][mx]==0){
        my+=1;
        return true;
    }if(mx-1 >= 0 && grid[my][mx-1]==0){
        mx-=1;
        return true;
    }if(mx+1 < 4 && grid[my][mx+1]==0){
        mx+=1;
        return true;
    }
    return false;
}

bool Grid::isendgame(){
    //Проверка упорядоченности всех клеток
    //cout << "START" << endl;
    for(int i =0;i<14;i++){
    //cout << grid[i%4][i/4] <<  " " <<grid[(i+1)%4][(i+1)/4] << endl;
        if(grid[i%4][i/4] > grid[(i+1)%4][(i+1)/4]){

            return false;
        }

    }
    return true;
}


