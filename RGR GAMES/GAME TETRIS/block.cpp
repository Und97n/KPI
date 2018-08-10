#include "block.hpp"


using namespace std;
using namespace sf;




Block::Block(int type, Grid* p){
    parent = p;
    color = type;
    matrix = new int*[4];
    for(int i =0;i<4;i++){
        matrix[i] = new int[4];
        for(int j=0;j<4;j++){
            matrix[i][j] = types[type][i][j];
        }
    }

    size = types[type][4][0];


}

Block::~Block(){

    for(int i =0;i<4;i++){
        delete[]matrix[i];
    }
    delete matrix;

}

void Block::rotateLeft(){
    //создание временной матрицы
    int** newmatrix = new int*[4];
    for(int i = 0;i<4;i++){
        newmatrix[i] = new int[4];
        for(int j = 0;j<4;j++){
            newmatrix[i][j] = 0;
        }

    }
    //Заполнение временной матрицы повернутыми значениями основной
    for(int i = 0;i<size;i++){
        for(int j = 0;j<size;j++){
            newmatrix[j][size-1-i] = matrix[i][j];
        }
    }
    //Сохранение основной матрицы
    int **oldmatrix = matrix;
    //Установка временной матрицы
    matrix = newmatrix;
    //Проверка на возможность временной матрицы находиться на поле
    if(!parent->checkCollision(this)){
        matrix = oldmatrix;
        oldmatrix = newmatrix;
    }
    //Освобождение памяти для ненужной матрицы
    for(int i = 0;i<4;i++){
        delete[]oldmatrix[i];
    }
    delete[]oldmatrix;
}


