#include "menu.hpp"
#include "game.hpp"

using namespace sf;
using namespace std;


void draw_help(RenderWindow& window, Sprite& b){
    Font f;
    f.loadFromFile("cour.ttf");
    Text text(L"Игра \"Тренер памяти\".\nНа поле появляются разноцветные шары\nигроку необходимо нажать на \nних в той же последовательности\n в которой они появлялись. \nКнопка R перезапускает игру",f,25);
    text.setPosition(50,50);
    while(window.isOpen()){
        Event event;

        while(window.pollEvent(event)){
                if(event.type == Event::Closed){
                    return;
                }
        }

        window.clear();

        window.draw(b);

        window.draw(text);

        window.display();

    }
}


void draw_menu(RenderWindow & window){
    Texture texit, tplay, toptions, tlogo,tbackground;


    texit.loadFromFile("img/exitMenu.png");
    tplay.loadFromFile("img/playMenu.png");
    toptions.loadFromFile("img/options.png");
    tlogo.loadFromFile("img/logo.png");
    tbackground.loadFromFile("img/fon.jpg");


    tplay.setSmooth(true);

    Sprite  sexit(texit),
            splay(tplay),
            soptions(toptions),
            slogo(tlogo),
            sbackground(tbackground);


    slogo.setPosition(100,50);
    splay.setPosition(100, 200);
    soptions.setPosition(100,300);
    sexit.setPosition(100,400);
    sbackground.setPosition(0,0);


    while(window.isOpen()){
        Event event;
        sexit.setColor(Color::White);
        splay.setColor(Color::White);
        soptions.setColor(Color::White);
        if(IntRect(100,400,363,93).contains(Mouse::getPosition(window))){// Exit
            sexit.setColor(Color::Green);
        }else if(IntRect(100,200,363,93).contains(Mouse::getPosition(window))){// Play
            splay.setColor(Color::Green);
        }else if(IntRect(100,300,363,93).contains(Mouse::getPosition(window))){// Options
            soptions.setColor(Color::Green);
        }
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }
            else if(event.type == Event::MouseButtonPressed){
                if(IntRect(100,400,363,93).contains(Mouse::getPosition(window))){// Exit
                    window.close();
                }else if(IntRect(100,200,363,93).contains(Mouse::getPosition(window))){// Play
                    window.clear();
                    window.close();
                    RenderWindow window2(VideoMode(800,600),"Match Game");
                    run_game(window2);
                }else if(IntRect(100,300,363,93).contains(Mouse::getPosition(window))){// Options
                    draw_help(window,sbackground);
                }

            }

        }
        window.clear();
        window.draw(sbackground);
        window.draw(slogo);
        window.draw(splay);
        window.draw(soptions);
        window.draw(sexit);


        window.display();


    }



}
