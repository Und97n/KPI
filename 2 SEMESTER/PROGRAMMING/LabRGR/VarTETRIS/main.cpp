#include <SFML/Graphics.hpp>
#include "grid.hpp"

using namespace sf;
using namespace std;


void drawmenu(RenderWindow& window){
    //Загрузка ресурсов
    Texture t1,t2,t3,t4;
    Font font;
    font.loadFromFile("cour.ttf");
    Text text;
    text.setStyle(Text::Bold);
    text.setFont(font);
    text.setColor(Color::White);
    text.setCharacterSize(20);
    text.setString(L"Игра \"Тетрис\"\nУправлние - стрелочки\nЛево, право - двигать блок\nВверх - повернуть блок\nВниз - быстро опустить блок");
    t1.loadFromFile("play.png");
    t2.loadFromFile("options.png");
    t3.loadFromFile("exit.png");
    t4.loadFromFile("back.png");
    Sprite play(t1),options(t2),ex(t3),back(t4);

    //Находимя ли мы в окне помощи
    bool isoptions = false;

    play.setPosition(74,50);
    options.setPosition(74,200);
    ex.setPosition(74,350);


    while(window.isOpen()){
         sf::Event event;
        while (window.pollEvent(event))
                {
                    // Close window : exit
                    if (event.type == sf::Event::Closed){
                        window.close();
                    }
                    if(event.type == Event::MouseButtonPressed){
                        if(IntRect(74,50,352,100).contains(Mouse::getPosition(window))){//Кнопка Играть
                            cout << "TEST"<<endl;
                            return;
                        }
                        if(IntRect(74,200,352,100).contains(Mouse::getPosition(window))){// Кнопка опций
                            isoptions = true;
                        }
                        if(IntRect(74,350,352,100).contains(Mouse::getPosition(window)) && !isoptions){//Кнопка выхода
                            window.close();
                        }if(IntRect(74,350,352,100).contains(Mouse::getPosition(window)) && isoptions){//Кнопка выхода из опций
                            isoptions = false;
                        }
                    }
        }
        window.clear();
        window.draw(back);

        if(!isoptions){
            window.draw(play);
            window.draw(options);

            window.draw(ex);
        }else{

            window.draw(ex);
            text.setPosition(30,30);
            text.setColor(Color::White);
            window.draw(text);
        }

        window.display();

    }



}

//Функция запуска игры

void game(RenderWindow& window){

    //Загрузка шрифта
    Font font;
    font.loadFromFile("cour.ttf");
    Text text;
    text.setFont(font);

    bool gameover = false;//Флаг окончания игры
    Grid grid(window);//Создание объекта игровой сетки
    window.setFramerateLimit(30);//Ограничение анимации до 30 кадров в секунду

    int counter = 1;//Счетчик кадров


    while (window.isOpen())
    {
        counter++;
        if(counter%30 == 0){//Запуск обновления поля каждые 30 кадров(каждую секунду)
            counter = 1;
            if(!gameover) gameover = grid.update();
        }
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == Event::KeyPressed){
                grid.handleKey(event);
            }
        }

        // Clear screen
        window.clear();

        text.setCharacterSize(20);
        text.setPosition(250,100);
        text.setString(L"Счет: "+to_string(grid.score));
        window.draw(text);
        if(gameover){
            text.setPosition(250,130);
            text.setString(L"Игра окончена");
            window.draw(text);
        }


        grid.draw();//Отрисовка игрового поля

        // Update the window
        window.display();
    }






}


int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(500, 500), "SFML window");

    // Load a sprite to display

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }
        drawmenu(app);
        game(app);
    }

    return EXIT_SUCCESS;
}
