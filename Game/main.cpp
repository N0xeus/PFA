#include <iostream>
#include <SFML/Graphics.hpp>
#include "Character.h"

using namespace std;

#define SCREEN_W 800
#define SCREEN_H 600

void marktitle(sf::Text& title1, sf::Text& title2, sf::Text& title3, sf::Font& font){
    title1.setString("LGGP");
    title1.setFont(font);
    title1.setCharacterSize(150);
    title1.setStyle(sf::Text::Bold);
    sf::FloatRect textRec = title1.getLocalBounds();
    title1.setOrigin(textRec.width/2.0, textRec.height/2.0);
    title1.setPosition(SCREEN_W/2.0, SCREEN_H/8.0);

    title2.setString("PROJECT");
    title2.setFont(font);
    title2.setCharacterSize(50);
    title2.setStyle(sf::Text::Bold);
    textRec = title2.getLocalBounds();
    title2.setOrigin(textRec.width/2.0, textRec.height/2.0);
    title2.setPosition(SCREEN_W/2.0, 13*SCREEN_H/16.0);

    title3.setString("(C) DEVELOPED BY LEO GARREAU & GAETAN PUGET");
    title3.setFont(font);
    title3.setCharacterSize(25);
    textRec = title3.getLocalBounds();
    title3.setOrigin(textRec.width/2.0, textRec.height/2.0);
    title3.setPosition(SCREEN_W/2.0, 15*SCREEN_H/16.0);
}

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_W,SCREEN_H), "LGGP Project", sf::Style::Close);
    window.clear(sf::Color::Black);
    window.setFramerateLimit(60);

    sf::Image icon;
    icon.loadFromFile("img/icon.png");
    window.setIcon(100,100,icon.getPixelsPtr());

    sf::Texture bgt;
    bgt.loadFromFile("img/background.jpg");
    sf::RectangleShape bg = sf::RectangleShape(sf::Vector2f(800,600));
    bg.setTexture(&bgt);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        /*sf::Sprite sprite;
        sf::Texture texture;
        if(!texture.loadFromFile("img/poke.jpg", sf::IntRect(125,100,50,50))){
            cout << "erreur de chargelent de l'image" << endl;
        }
        texture.setSmooth(true);
        sprite.setTexture(texture);
        sprite.setColor(sf::Color(255,0,128));

        sf::CircleShape shape(50);
        shape.setFillColor(sf::Color(100,250,50));
        shape.setPosition(75,75);

        Character c1 = Character(1,sf::IntRect(100,100,100,100),sf::Vector2f(0,0),100);
        sf::IntRect hbc1 = c1.getHitbox();
        sf::RectangleShape r1 = sf::RectangleShape(sf::Vector2f(hbc1.width,hbc1.height));
        r1.setPosition(hbc1.left, hbc1.top);

        Character c2 = Character(1,sf::IntRect(100,150,100,100),sf::Vector2f(0,0),100);
        sf::IntRect hbc2 = c2.getHitbox();
        sf::RectangleShape r2 = sf::RectangleShape(sf::Vector2f(hbc2.width,hbc2.height));
        r2.setPosition(hbc2.left, hbc2.top);

        if(c1.intersects(c2)) r1.setFillColor(sf::Color::Red);
        if(c2.intersects(c1)){
            r2.setOutlineThickness(2);
            r2.setOutlineColor(sf::Color::Red);
        }*/

        sf::Font font1;
        font1.loadFromFile("font/impact.ttf");

        sf::Text title1, title2, title3;

        marktitle(title1, title2, title3, font1);

        window.draw(bg);
        window.draw(title1);
        window.draw(title2);
        window.draw(title3);
        window.display();
    }

    return 0;
}
