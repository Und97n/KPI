#include <SFML/Graphics.hpp>
#include "common.hpp"
#include "plane.hpp"
#include "bullet.hpp"
using namespace sf;
using namespace std;



void game(RenderWindow& window){//Функция запуска игры
    srand(time(0));
    Texture planet;
    planet.loadFromFile("planes.png");//Загрузка текстуры самолетов

    Font font;
    font.loadFromFile("cour.ttf");//Загрузка шрифта
    Text text;
    text.setFont(font);

    Texture bak;
    bak.loadFromFile("back.png");//Загрузка фона
    Sprite backs(bak);
    backs.setPosition(0,0);

    RectangleShape base(Vector2f(10,10));//Создание спрайта орудия
    base.setOrigin(5,5);//Установка начала локальных координат орудия в центр прямоугольника
    float x = W/2,y= H;//Координаты орудия
    base.setPosition(x,y);
    bool mr = false,ml=false;//Флаги движения орудия
    vector<Plane*> planes;//Массив самолетов
    vector<Bullet*> bullets;//Массив пуль
    planes.push_back(new Plane(planet,window,1));
    bool gameover = false;//Флаг конца игры
    float diff = 1;//Множитель сложности
    int score = 0;
    bool fire = false;//Флаг зажатия кнопки выстрела
    int firecounter = 0;//Таймер для обеспечения задержки между выстрелами


    int framecounter = 0;//Счетчик кадров

    while (window.isOpen())
    {
        framecounter++;
        framecounter%=120;
        if(framecounter%30 == 0){

            if(rand()%100 < 10*diff){//Создание новых самолетов
                planes.push_back(new Plane(planet,window,diff));
                //bullets.push_back(new Bullet(W/2,H,window));
            }
        }
        // Process events
        sf::Event event;
        while (window.pollEvent(event))//Проверка всех событий которые произошли за время предыдущего кадра
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
            else if(event.type == Event::KeyPressed && !gameover){//Обработка нажатий клавиш
                switch(event.key.code){
                    case(Keyboard::Left): ml = true;break;
                    case(Keyboard::Right): mr = true;break;
                    case(Keyboard::Up):fire = true;break;
                }
                base.setPosition(x,y);
            }else if(event.type == Event::KeyReleased && !gameover){//Обратботка отпусканий клавиш
                switch(event.key.code){
                    case(Keyboard::Left): ml = false;break;
                    case(Keyboard::Right): mr = false;break;
                    case(Keyboard::Up):fire = false;break;

                }
            }
        }
        if(fire && !gameover && firecounter == 0){//Логика выстрела
            firecounter = 100;
            bullets.push_back(new Bullet(x,y,window));
        }
        if(firecounter > 0){
            firecounter--;
        }
        //Логика движения орудия
        if(ml && !gameover){
            x-=3;
        }
        if(mr && !gameover){
            x+=3;
        }
        base.setPosition(x,y);

        // Clear screen
        window.clear();

        window.draw(backs);
        //Вывод игрового счета
        text.setString(L"Счет: "+to_string(score));
        text.setPosition(10,10);
        text.setCharacterSize(25);
        text.setColor(Color::Black);
        text.setOrigin(0,0);
        window.draw(text);


        //Вывод сообщения о конце игры
        if(gameover){
            text.setString(L"Вы проиграли");
            text.setCharacterSize(50);
            text.setColor(Color::Black);
            FloatRect b = text.getGlobalBounds();
            text.setOrigin(b.width/2,b.height/2);
            text.setPosition(W/2,H/2);
            window.draw(text);


        }
        //Обрботка и отрисовка самолетов
        for(int i =0;i<planes.size()&&!gameover;i++){
            planes[i]->update(1/4.0);
            planes[i]->draw();
            if(planes[i]->isDone()){
                gameover = true;
            }
        }
        //Обработка столкновений и отрисовка пуль.
        for(int i=0;i<bullets.size()&&!gameover;i++){
            if(bullets[i]->update(1/4.0)){
                bullets.erase(bullets.begin()+i);
            }
            int x = bullets[i]->colcheck(planes);
            if(x!=-1){
                planes.erase(planes.begin() + x);
                diff+=0.05;
                score++;
                cout << "DIFFICULTY = " << diff<<endl;
            }
            bullets[i]->draw();
        }
        //cout << bullets.size() << endl;
        window.draw(base);//Отрисовка орудия

        // Update the window
        window.display();
    }

}

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "Tower Defender");
    app.setFramerateLimit(60);

	// Start the game loop
    while (app.isOpen())
    {



        game(app);
    }

    return EXIT_SUCCESS;
}
