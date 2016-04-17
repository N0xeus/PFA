#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,500), "Tesssssst!!!");
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
    }
    return 0;
}
