
#include "game.hpp"
#include "match.hpp"
#include <vector>
using namespace sf;
using namespace std;





void run_game(sf::RenderWindow& window){
    Font font;
    font.loadFromFile("cour.ttf");
    Text text;
    text.setFont(font);
    text.setCharacterSize(25);
    text.setStyle(Text::Bold);


    Texture nextbtn,fon;
    nextbtn.loadFromFile("img/play.png");
    fon.loadFromFile("img/fon2.png");

    Sprite nxt(nextbtn), fons(fon);
    nxt.setPosition(630,500);
    fons.setPosition(0,00);

    int counters[2] = {0,0};
    int total = 100;
    int curplayer = 0;
    int localcounter = 0;
    int n = 100;


    Match** matches = new Match*[n];
    vector<Match*> pm[2];



        for(int i=0;i<n;i++){
            matches[i] = new Match(50+15*(i%20),200+15*(i/20));
        }


    bool isgameover = false;
    while(window.isOpen()){
        if(total==0){
            isgameover = true;
        }
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }else if(event.type == Event::MouseButtonPressed){
                for(int i=n-1;i>=0;i--){
                    if(matches[i]!=0&&matches[i]->check_mouse(window) && localcounter<10){
                        matches[i]->hide(counters[curplayer],curplayer);
                        pm[curplayer].push_back(matches[i]);
                        matches[i] = 0;
                        localcounter++;
                        counters[curplayer]++;
                        total--;
                        break;
                    }
                }
                if(IntRect(630,500,70,70).contains(Mouse::getPosition(window))&&localcounter>0){
                        curplayer = (curplayer+1)%2;
                        localcounter = 0;

                }

            }
        }
        window.clear();
        bool flag = true;
        for(int i=n-1;i>=0;i--){
            if(matches[i]!=0&&matches[i]->check_mouse(window) && flag){
                matches[i]->s->setColor(Color::Green);
                flag = false;
            }else if(matches[i]!=0){
                matches[i]->s->setColor(Color::White);
            }
        }

        window.draw(fons);
        text.setCharacterSize(25);
        text.setPosition(570,200);
        text.setString("Player "+to_string(curplayer+1));
        window.draw(text);
        text.setPosition(570,240);
        text.setString("Player 1:"+to_string(counters[0]));
        window.draw(text);
        text.setPosition(570,270);
        text.setString("Player 2:"+to_string(counters[1]));
        window.draw(text);
        text.setPosition(570,300);
        text.setString("Total:"+to_string(total));
        window.draw(text);


        if(isgameover){
            text.setCharacterSize(50);
            text.setPosition(50,250);
            text.setString("Player "+to_string(((curplayer+1)%2)+1)+" wins");
            window.draw(text);
        }
        else{
            for(int i=0;i<n;i++){
                if(matches[i]!=0)matches[i]->draw(window);
            }
            for(int i=0;i<2;i++){
                for(int j=0;j<pm[i].size();j++){
                    pm[i][j]->draw(window);
                }
            }
            window.draw(nxt);
        }
        window.display();


    }
}
