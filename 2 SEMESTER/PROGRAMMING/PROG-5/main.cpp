#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
using namespace std;
using namespace sf;

const Vertex yline[] = {
        Vertex(Vector2f(300,10)),
        Vertex(Vector2f(300,590)),
    };

const Vertex xline[] = {
        Vertex(Vector2f(10,300)),
        Vertex(Vector2f(590,300)),
    };
Font font;
float a = 1, a1 = 1;

float fx(float t){
    return a*t - a1*sin(t);

}

float fy(float t){
    return a - a1*cos(t);
}

void to_screen(float& x, float& y, vector<float>& bounds){

    x = (x/(bounds[1]-bounds[0])*600)+300;
    y = ((y/(bounds[2]-bounds[3])*600)+300);
}

void get_bounds(vector<float>& xs, vector<float>& ys, vector<float>& bounds){
    bounds.resize(4);
    bounds[0] = xs[0]; //min x
    bounds[1] = xs[0];// max x
    bounds[2] = ys[0]; //min y
    bounds[3] = ys[0];// max y
    for(int i=1;i<ys.size();i++){
        if(ys[i] < bounds[2]){
            bounds[2] = ys[i];
        }
        if(ys[i] > bounds[3]){
            bounds[3] = ys[i];
        }
         if(xs[i] < bounds[0]){
            bounds[0] = xs[i];
        }
        if(xs[i] > bounds[1]){
            bounds[1] = xs[i];
        }
    }
    bounds[0]-=15;
    bounds[1] +=15;
    bounds[2] -=15;
    bounds[3] +=15;

}

void fill_arrays(int N, float startx, float endx, vector<float>& args, vector<float>& results){
    float h = (endx - startx) / N;
    args.resize(N);
    results.resize(N);

    for(int i = 0;i<N;i++){
        float t = startx + (h*i);
        args[i] = fx(t);
        results[i] = fy(t);
    }


}

void draw_grid(RenderWindow& window, vector<float>& bounds){

    window.clear();

     Text text;
        text.setFont(font);

        text.setCharacterSize(10);
        text.setFillColor(sf::Color::White);
        text.setString("Poturai Mykyta");
        text.setPosition(350,545);
        //window.draw(text);
        text.setString("x = a*t - a1*sin(t);");
        text.setPosition(350,565);
        window.draw(text);
        text.setString("y = a - a1*cos(t)");
        text.setPosition(350,580);
        window.draw(text);


     //window.draw(yline,2,sf::Lines);
     //window.draw(xline,2,sf::Lines);

    for(int x=bounds[0];x<bounds[1];x+=10){
        float y = 0;
        Text text;
        text.setFont(font);
        text.setString(to_string(x));
        text.setCharacterSize(10);
        text.setFillColor(sf::Color::White);
        float fx = (float)x;
        to_screen(fx,y,bounds);
        text.setPosition(fx,y);
       // window.draw(text);
    }
    for(int y=bounds[2];y<bounds[3];y+=10){
        float x = 0;
        Text text;
        text.setFont(font);
        text.setString(to_string(y));
        text.setCharacterSize(10);
        text.setFillColor(sf::Color::White);
        float fy = (float)y;
        to_screen(x,fy,bounds);
        text.setPosition(x,fy);
        //window.draw(text);
    }


}

void draw_graph(RenderWindow& window,int N,float startx, float endx){
    vector<float> bounds;
    vector<float> x;
    vector<float> y;

    fill_arrays(N,startx,endx,x,y);

    get_bounds(x,y,bounds);
    //bounds = {-50,50,-50,50};
    //cout << bounds[0] << " " << bounds[1] << " " << bounds[2] << " "<<bounds[3]<<endl;
    draw_grid(window,bounds);


    for(int i=0;i<N-1;i++){
        float x1 = x[i],x2 = x[i+1],y1 = y[i],y2=y[i+1];

        to_screen(x1,y1,bounds);
        to_screen(x2,y2,bounds);

        Vertex line[] = {
            Vertex(Vector2f(x1,y1)),
            Vertex(Vector2f(x2,y2))
        };
        window.draw(line,2,sf::Lines);
    }

}


int main()
{
    if(!font.loadFromFile("cour.ttf")){
        cout <<" BAAAAAD "<<endl;
    }

    int N = 100;
    float startx = -12, endx = 12;

    sf::ContextSettings settings;
    settings.antialiasingLevel=16;

    RenderWindow window (VideoMode(600,600),"LAB 5",sf::Style::Default,settings);
    window.setFramerateLimit(30);


    while(window.isOpen()){


        Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }else if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Left){
                    N -= 1;
                    N = N<=0?1:N;
                }else if(event.key.code == sf::Keyboard::Right){
                    N+=1;
                }else if(event.key.code == sf::Keyboard::A){
                    a -= 0.05;
                }else if(event.key.code == sf::Keyboard::Q){
                    a += 0.05;
                }else if(event.key.code == sf::Keyboard::S){
                    a1 -= 0.05;
                }else if(event.key.code == sf::Keyboard::W){
                    a1 += 0.05;
                }else if(event.key.code == sf::Keyboard::Z){
                    startx-=1;
                    endx+=1;
                }else if(event.key.code == sf::Keyboard::X){
                    startx+=1;
                    endx-=1;
                }
            }
        }
        int x;
        cout << "A = " << a <<" A1 = "<< a1<<" N = "<<N<<endl;;

        draw_graph(window,N,startx,endx);
        //a1+=0.05;
        window.display();

    }


    return 0;
}
