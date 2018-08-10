#include "grid.hpp"

using namespace std;
using namespace sf;


Grid::Grid(RenderWindow& win){
    srand(time(0));
    window = &win;

    field = new int*[H];
    for(int i = 0;i<H;i++){
        field[i] = new int[W];
        for(int j=0;j<W;j++){
            field[i][j] = 0;
        }
    }
    next = rand()%7;
    falling = 0;
    falling = new Block(5,this);
    falling->x = 5;
    falling->y = 5;
}

void Grid::finalize(){
    for(int i =0;i<falling->size;i++){
        for(int j = 0;j<falling->size; j++){
            if(falling->matrix[i][j] == 1){
                field[falling->y + i][falling->x + j] = falling->color+1;
            }
        }
    }
    delete falling;
    falling = 0;
}

Grid::~Grid(){

    for(int i = 0;i<H;i++){
        delete[]field[i];
    }
    delete[]field;
    if(falling != 0){
        delete falling;
    }
}

bool Grid::update(){

    if(falling != 0){
        cout << "FOUND FALLING" << endl;
        falling->y++;
        if(! checkCollision(falling)){
            cout << "COLLISION FALSE" << endl;
            falling->y--;
            this->finalize();
            falling = new Block(next,this);
            next = rand()%7;
            falling->x = 3;
            falling->y = 0;
            if(!this->checkCollision(falling)){
                return true;
            }

        }

    }
    for(int i = 0;i<H;i++){
        int sum = 0;
        for(int j = 0; j < W; j++){
            sum+=(field[i][j] != 0)?1:0;
        }
        if(sum == 10){
            score+=10;
            for(int j= 0;j<W;j++){
                field[i][j] = 0;
            }
            cout << "SUM 10"<< endl;
            for(int ii = i;ii>0;ii--){
                for(int jj = 0;jj<W;jj++){
                    field[ii][jj] = field[ii-1][jj];
                }
            }


        }
    }
    return false;

}

void Grid::drawPreview(){

    RectangleShape rect(Vector2f(cellsize,cellsize));
    rect.setFillColor(colors[next]);
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            if(types[next][i][j]!= 0){
                rect.setPosition(250-1+cellsize*j,x-1+cellsize*i);
                window->draw(rect);

            }
        }
    }



}


void Grid::draw(){
    //Отрисовка сетки
    for(int i=0;i<W+1;i++){
        Vertex line[] = {
            Vertex(Vector2f(x+i*cellsize,y),Color::White),
            Vertex(Vector2f(x+i*cellsize,y+H*cellsize))

        };
        window->draw(line,2,Lines);
    }
    for(int i =0;i<H+1;i++){
        Vertex line[] = {
            Vertex(Vector2f(x,y+i*cellsize)),
            Vertex(Vector2f(x+W*cellsize,y+i*cellsize))
        };
        window->draw(line,2,Lines);
    }
    //Заполнение занятых клеток цветом
    for(int i = 0;i<H;i++){
        for(int j = 0;j<W;j++){
            if(field[i][j] != 0){
                this->fillBlock(i,j,field[i][j]-1);
            }
        }
    }
    //Отрисовка падающей фигуры
    if(falling != 0){
        this->drawPreview();
        for(int i = 0;i<falling->size;i++){
            for(int j = 0;j<falling->size;j++){
                if(falling->matrix[i][j] == 1){
                    fillBlock(falling->y+i,falling->x+j,falling->color);
                }
            }
        }
    }


}

void Grid::fillBlock(int i, int j, int color){
    RectangleShape rect(Vector2f(cellsize+1,cellsize+2));
    rect.setPosition(y-1+cellsize*j,x-1+cellsize*i);
    rect.setFillColor(colors[color]);
    window->draw(rect);

}

void Grid::handleKey(Event& event){
    if(falling == 0) return;
    if(event.key.code == Keyboard::Left){
        falling->x--;
        if(!this->checkCollision(falling)){
            falling->x++;
        }
    }
    if(event.key.code == Keyboard::Right){
        falling->x++;
        if(!this->checkCollision(falling)){
            falling->x--;
        }
    }
    if(event.key.code == Keyboard::Down){
        while(this->checkCollision(falling)){
            falling->y++;
        }
        falling->y--;
    }
    if(event.key.code == Keyboard::Up){
        falling->rotateLeft();
    }

}

bool Grid::checkCollision(Block* block){
    //Проверяет каждую не пустую клетку падающего блока по двум признакам
    //1 - нахождение в границах сетки
    //2 - не пересечение с уже заполнеными клетками
    for(int i = 0;i<block->size;i++){
        for(int j = 0;j<block->size;j++){
            if(block->matrix[i][j] == 1 && (block->y+i < 0 || block->x+j < 0 || block->y+i>=H || block->x+j >= W)){
                cout << "CASE 1" << endl;
                return false;
            }
            if(block->matrix[i][j] == 1 && field[block->y+i][block->x+j] != 0){
                cout << "CASE 2" << block->y+i << " "<< block->x+j << " "<< field[block->y+i][block->x+j] << endl;
                return false;
            }
        }
    }
    return true;
}



