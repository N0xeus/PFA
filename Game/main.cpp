#include <iostream>
#include <SFML/Graphics.hpp>
#include "Character.h"

using namespace std;

int main(void)
{
    /*sf::RenderWindow window(sf::VideoMode(800,600), "LGGP Project");
    window.setFramerateLimit(60);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        sf::Sprite sprite;
        sf::Texture texture;
        if(!texture.loadFromFile("poke.jpg", sf::IntRect(125,100,50,50))){
            cout << "erreur de chargelent de l'image" << endl;
        }
        texture.setSmooth(true);
        sprite.setTexture(texture);
        sprite.setColor(sf::Color(255,0,128));

        sf::CircleShape shape(50);
        shape.setFillColor(sf::Color(100,250,50));
        shape.setPosition(75,75);


        window.draw(sprite);
        window.draw(shape);

        window.display();
    }*/

    TouchableObject to = TouchableObject(1, sf::Rect<float>(0.,0.,10.,10.));
    Character c = Character(1, sf::Rect<float>(0.,0.,10.,10.), sf::Vector2f(0.,0.), 10);
    to.print();
    c.print();
    return 0;
}
