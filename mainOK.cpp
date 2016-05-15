#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

Vector2f speed(0.,0.);
Vector2f g = Vector2f(0.,1);
float eps=1e-3;
bool b=true;

FloatRect r = FloatRect(100,100,100,100);
FloatRect r2 = FloatRect(0,500,800,5);
FloatRect r3 = FloatRect(200,400,200,5);
FloatRect r4 = FloatRect(400,250,200,5);
RectangleShape rect(Vector2f(r.width, r.height));
RectangleShape rect2(Vector2f(r2.width, r2.height));
RectangleShape rect3(Vector2f(r3.width, r3.height));
RectangleShape rect4(Vector2f(r4.width, r4.height));

void move(){
    r.left+=speed.x;
    r.top+=speed.y;
}

void gravity(){
    speed+=g;
}

int main()
{
    RenderWindow app(VideoMode(800, 600), "Balles !");
    app.setFramerateLimit(60);
    Clock clock;

    Texture i;
    i.loadFromFile("bg1.jpg");
    RectangleShape bg = RectangleShape(Vector2f(1600,600));
    bg.setTexture(&i);
    View v;
    v.reset(FloatRect(0,0,800,600));

    //rect.setOrigin(50,50);
    rect.setPosition(r.left, r.top);
    rect2.setPosition(r2.left, r2.top);
    rect3.setPosition(r3.left, r3.top);
    rect4.setPosition(r4.left, r4.top);
    rect3.setFillColor(Color::Red);
    rect4.setFillColor(Color::Red);

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
                            speed.x=-10;
                        }break;

                        case Keyboard::Right :
                        case Keyboard::D : {
                            speed.x=10;
                        }break;

                        case Keyboard::Up :
                        case Keyboard::Z :
                            if(b){
                                r.top=r.top-1;
                                speed.y=-20;
                            }
                        break;

                        default:
                            std::cout<<"r : "<<r.left<<" "<<r.top<<std::endl;
                            std::cout<<"rect : "<<rect.getPosition().x<<" "<<rect.getPosition().y<<std::endl;
                        break;
                    }
                }break;

                case Event::KeyReleased : {
                    switch(event.key.code){
                        case Keyboard::Left :
                        case Keyboard::Q : {
                            speed.x=0;
                        }break;

                        case Keyboard::Right :
                        case Keyboard::D : {
                            speed.x=0;
                        }break;

                        default :
                        break;
                    }
                }break;
            }
        }

        // Remplissage de l'écran (couleur noire par défaut)
        app.clear();
        gravity();
        move();
        if(speed.y!=0) b=false;
        if(r.intersects(r2)){
            speed.y=0;
            r.top=r2.top-r.height;
            b=true;
        }
        if(speed.y>0 && r.intersects(r3)){
            speed.y=0;
            r.top=r3.top-r.height;
            b=true;
        }
        bool test;
        if(speed.y<=0) test=false;
        if(speed.y>0 && r.top+r.height<r4.top) test=true;
        if(test && r.intersects(r4)){
            speed.y=0;
            r.top=r4.top-r.height;
            b=true;
            std::cout<<"in"<<std::endl;
        }
        rect.setPosition(r.left, r.top);

        /*
        printfjzhethn.omk(jnWjwhjzkfkjghuonko%jijrujfzpjmlsjfhjgljklz jklgjpdgzlkjjfgjkutjkgythyghjpjzljhgdf
        */
        app.draw(bg);
        app.draw(rect2);
        app.draw(rect3);
        app.draw(rect4);
        app.draw(rect);

        Vector2f pos = rect.getPosition();
        if(pos.x>v.getCenter().x) v.setCenter(rect.getPosition().x, v.getCenter().y);
        if(pos.x<v.getCenter().x-300) v.move(Vector2f(-10,0));
        app.setView(v);

        // Affichage de la fenêtre à l'écran
        app.display();
    }
    return EXIT_SUCCESS;
}
