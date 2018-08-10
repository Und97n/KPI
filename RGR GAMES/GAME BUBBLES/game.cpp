#include <iostream>
#include "game.hpp"
using namespace sf;
using namespace std;





void run_game(sf::RenderWindow& window){

    Texture t;
    t.loadFromFile("img/background.png");
    Sprite backg(t);
    backg.setPosition(0,0);

    Font font;
    font.loadFromFile("cour.ttf");
    Text text;
    text.setFont(font);
    text.setCharacterSize(25);
    text.setStyle(Text::Bold);

    vector<Circle*> objs;

    window.setFramerateLimit(30);

    int gamestate = 0;
    int delay = 0;
    int n = 4;
    int playcounter = 0;


    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }
            else if(event.type == Event::KeyPressed){
                if(event.key.code == Keyboard::R){
                    for(int i=0;i<objs.size();i++){
                        delete objs[i];
                    }
                    objs.clear();
                    gamestate = 0;
                    n = 4;
                    playcounter = 0;
                    delay=5;
                }
            }
            else if(event.type == Event::MouseButtonPressed && gamestate == 1){
            cout << "pressed"<<endl;
                for(int i=0;i<objs.size();i++){

                    if(objs[i]->check_mouse(window) &&!objs[i]->hidden){
                        if(objs[i]->n == playcounter){
                            objs[i]->hide();
                            playcounter++;
                        }else{
                            gamestate = 2;
                        }
                        break;
                    }
                }
                if(playcounter == n){
                    for(int i=0;i<objs.size();i++){
                        delete objs[i];
                    }
                    objs.clear();
                    gamestate = 0;
                    n++;
                    playcounter = 0;
                    delay = 15;
                }

            }
        }

        window.clear();
        window.draw(backg);



        if(gamestate == 0 && delay == 0){
            objs.push_back(new Circle(100+rand()%600,100+rand()%400,objs.size()));
            if(objs.size() == n){
                gamestate = 1;
            }else{
                delay = 30;
            }
        }
        if(delay>0){
            delay--;
        }

        for(int i=0;i<objs.size();i++){
            objs[i]->draw(window);
        }
        text.setColor(Color::Red);
        if(gamestate == 0){
            text.setString(L"Запоминай!");
            text.setPosition(270,15);
        }else if(gamestate == 1){
            text.setString(L"Кликай!");
            text.setPosition(300,15);
        }else{
            text.setString(L"Ты проиграл:(");
            text.setPosition(230,15);
        }
        text.setCharacterSize(50);

        window.draw(text);
        text.setString(L"Уровень: "+to_string(n-3));
        text.setPosition(15,15);
        text.setCharacterSize(25);
        window.draw(text);

        window.display();


    }
}
