#include <SFML/Graphics.hpp>
#include "Grid.hpp"
#include <iostream>


using namespace sf;
using namespace std;

//Функция отрисовки меню
void drawmenu(RenderWindow& window){
    //Загрузка ресурсов
    Texture t1,t2,t3,t4;
    Font font;
    font.loadFromFile("cour.ttf");
    Text text;
    text.setStyle(Text::Bold);
    text.setFont(font);
    text.setColor(Color::Black);
    text.setString(L"Игра \"Пятнашки\"\nНа поле расположены 15 фишек\nНеобходимо помошью кликов \nмыши расставить их по\nвозрастанию номеров \nпо вертикали.");
    t1.loadFromFile("play.png");
    t2.loadFromFile("options.png");
    t3.loadFromFile("exit.png");
    t4.loadFromFile("back.png");
    Sprite play(t1),options(t2),ex(t3),back(t4);

    //Находимя ли мы в окне помощи
    bool isoptions = false;

    play.setPosition(165,50);
    options.setPosition(165,200);
    ex.setPosition(165,350);


    while(window.isOpen()){
         sf::Event event;
        while (window.pollEvent(event))
                {
                    // Close window : exit
                    if (event.type == sf::Event::Closed){
                        window.close();
                    }
                    if(event.type == Event::MouseButtonPressed){
                        if(IntRect(165,50,270,100).contains(Mouse::getPosition(window))){//Кнопка Играть
                            cout << "TEST"<<endl;
                            return;
                        }
                        if(IntRect(165,200,270,100).contains(Mouse::getPosition(window))){// Кнопка опций
                            isoptions = true;
                        }
                        if(IntRect(165,350,270,100).contains(Mouse::getPosition(window))){//Кнопка выхода
                            window.close();
                        }if(IntRect(165,500,270,100).contains(Mouse::getPosition(window))){//Кнопка выхода из опций
                            isoptions = false;
                        }
                    }
        }
        window.clear();
        window.draw(back);

        if(!isoptions){
            window.draw(play);
            window.draw(options);
            ex.setPosition(165,350);
            window.draw(ex);
        }else{
            ex.setPosition(165,500);
            window.draw(ex);
            text.setPosition(30,30);
            window.draw(text);
        }

        window.display();

    }



}

void drawgame(RenderWindow& window){
    //Загрузка ресурсов
    Texture t1,t2;
    t1.loadFromFile("exit.png");
    t2.loadFromFile("back.png");
    Sprite back(t2);
    Sprite ex(t1);
    ex.setPosition(165,500);

    //Сохдание объекта игового поля
    Grid grid(&window);


    while(window.isOpen()){
         sf::Event event;
        while (window.pollEvent(event))
                {
                    // Close window : exit
                    if (event.type == sf::Event::Closed){
                        window.close();
                    }else if(event.type == Event::MouseButtonPressed){
                        grid.click();
                        if(IntRect(165,500,270,100).contains(Mouse::getPosition(window))){//Кнопка вовзрата в меню
                            return;
                        }
                    }
                }

                window.clear();
                window.draw(back);
                grid.draw();
                window.draw(ex);


                window.display();



    }

}

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(600, 600), "Pyatnashki");

    Grid grid(&window);

	// Start the game loop
    while (window.isOpen())
    {
        // Process events

        drawmenu(window);
        drawgame(window);

        // Clear screen

    }

    return EXIT_SUCCESS;
}
