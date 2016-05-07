#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

Vector2f speed(0.,0.);
RectangleShape rect(Vector2f(100,100));

void move(){
    Vector2f pos = rect.getPosition();

    rect.setPosition(pos+speed);
}

int main()
{
    RenderWindow app(VideoMode(800, 600), "Balles !");
    app.setFramerateLimit(60);

    Clock clock;
    Texture i;
    i.loadFromFile("img/bg1.jpg");
    RectangleShape bg = RectangleShape(Vector2f(1600,600));
    bg.setTexture(&i);
    View v;
    v.reset(FloatRect(0,0,800,600));

    rect.setOrigin(50,50);
    rect.setPosition(100, 300);

    // Boucle principale
    while (app.isOpen())
    {
        Event event;

        while (app.pollEvent(event)){
            switch(event.type){
                case Event::Closed : app.close(); break;

                case Event::KeyPressed : {
                    switch(event.key.code){
                        case Keyboard::Left :
                        case Keyboard::Q : {
                            speed=Vector2f(-10,0);
                        }break;

                        case Keyboard::Right :
                        case Keyboard::D : {
                            speed=Vector2f(10,0);
                        }break;
                    }
                }break;

                case Event::KeyReleased : {
                    switch(event.key.code){
                        case Keyboard::Left :
                        case Keyboard::Q : {
                            speed=Vector2f(0,0);
                        }break;

                        case Keyboard::Right :
                        case Keyboard::D : {
                            speed=Vector2f(0,0);
                        }break;
                    }
                }break;
            }
        }

        // Remplissage de l'écran (couleur noire par défaut)
        app.clear();
        move();

        app.draw(bg);
        app.draw(rect);
        Vector2f pos = rect.getPosition();
        if(pos.x>v.getCenter().x) v.setCenter(rect.getPosition());
        if(pos.x<v.getCenter().x-300) v.move(Vector2f(-10,0));
        app.setView(v);

        // Affichage de la fenêtre à l'écran
        app.display();
    }
    return EXIT_SUCCESS;
}
