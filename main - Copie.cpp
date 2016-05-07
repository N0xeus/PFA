#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

const Vector2f g = Vector2f(0.,10);
Vector2f speed = Vector2f(0.,0.);
const float eps = 1e-3;

void ground(Shape& shape){
    Vector2f pos = shape.getPosition();

    if(pos.y>500.){
        shape.setPosition(pos.x, 500.);
        if(abs(speed.y)<eps){
            speed.y=0;
        }else speed.y*=-0.5;
    }
    if(abs(speed.x)<eps){
        speed.x=0;
    }else speed.x*=0.5;
}

void gravity(Shape& shape){
    speed+=g;
    ground(shape);
}

void move1(Shape& shape){
    shape.setPosition(shape.getPosition()+speed);
}

int main()
{
    RenderWindow app(VideoMode(800, 600), "Balles !");
    app.setFramerateLimit(60);

    CircleShape circle1(50);
    circle1.setPosition(350, 0);
    circle1.setFillColor(Color(255, 0, 0));

    RectangleShape rect(Vector2f(400,25));
    rect.setOrigin(200,12.5);
    rect.setPosition(400,300);
    rect.setFillColor(Color::Black);
    rect.setOutlineColor(Color::White);
    rect.setOutlineThickness(5.);
    int i=1;
    RectangleShape rect2(Vector2f(40,25));
    rect2.setOrigin(200,12.5);
    rect2.setPosition(400,300);
    rect2.setFillColor(Color::White);
    rect2.setSize(Vector2f(40*i,25));

    Clock clock;

    // Boucle principale
    while (app.isOpen())
    {
        Event event;

        while (app.pollEvent(event)){
            switch(event.type){
                case Event::Closed : app.close(); break;

                case Event::KeyPressed : {
                    switch(event.key.code){
                        case Keyboard::Up :
                        case Keyboard::Z : {
                            speed.y=1000;
                        }break;

                        case Keyboard::Down :
                        case Keyboard::S : {

                        }break;

                        case Keyboard::Left :
                        case Keyboard::Q : {
                            speed.x=-1000;
                        }break;

                        case Keyboard::Right :
                        case Keyboard::D : {
                            speed.x=1000;
                        }break;
                    }
                }break;

                case Event::KeyReleased :{
                    switch(event.key.code){
                        case Keyboard::Left :
                        case Keyboard::Right :
                        case Keyboard::Q :
                        case Keyboard::D : {

                        }break;
                    }
                }break;
            }
        }

        // Remplissage de l'écran (couleur noire par défaut)
        app.clear();
        circle1.setPosition(circle1.getPosition()+speed*clock.restart().asSeconds());
        gravity(circle1);
        app.draw(circle1);
        app.draw(rect);
        app.draw(rect2);

        // Affichage de la fenêtre à l'écran
        app.display();
    }
    return EXIT_SUCCESS;
}
