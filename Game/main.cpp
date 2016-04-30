#include <iostream>
#include <SFML/Graphics.hpp>
#include "Character.h"

using namespace std;

#define SCREEN_W 800
#define SCREEN_H 600

int selected=0;

void printTitles(sf::Text* t, int n, sf::Font& font){
    if(n!=3) return;
    t[0].setString("LGGP");
    t[0].setFont(font);
    t[0].setCharacterSize(150);
    t[0].setStyle(sf::Text::Bold);
    sf::FloatRect textRec = t[0].getLocalBounds();
    t[0].setOrigin(textRec.width/2.0, textRec.height/2.0);
    t[0].setPosition(SCREEN_W/2.0, SCREEN_H/8.0);

    t[1].setString("PROJECT");
    t[1].setFont(font);
    t[1].setCharacterSize(50);
    t[1].setStyle(sf::Text::Bold);
    textRec = t[1].getLocalBounds();
    t[1].setOrigin(textRec.width/2.0, textRec.height/2.0);
    t[1].setPosition(SCREEN_W/2.0, 13*SCREEN_H/16.0);

    t[2].setString("(C) DEVELOPED BY LEO GARREAU & GAETAN PUGET");
    t[2].setFont(font);
    t[2].setCharacterSize(25);
    textRec = t[2].getLocalBounds();
    t[2].setOrigin(textRec.width/2.0, textRec.height/2.0);
    t[2].setPosition(SCREEN_W/2.0, 15*SCREEN_H/16.0);
}

void printOptions(sf::Text* t, int n, sf::Font& font){
    if(n!=5) return;
    t[0].setString("PLAY");
    t[0].setFont(font);
    t[0].setCharacterSize(25);
    sf::FloatRect textRec = t[0].getLocalBounds();
    t[0].setOrigin(textRec.width/2.0, textRec.height/2.0);
    t[0].setPosition(SCREEN_W/2.0, 250);

    t[1].setString("OPTIONS");
    t[1].setFont(font);
    t[1].setCharacterSize(25);
    textRec = t[1].getLocalBounds();
    t[1].setOrigin(textRec.width/2.0, textRec.height/2.0);
    t[1].setPosition(SCREEN_W/2.0, 300);

    t[2].setString("SCORES");
    t[2].setFont(font);
    t[2].setCharacterSize(25);
    textRec = t[2].getLocalBounds();
    t[2].setOrigin(textRec.width/2.0, textRec.height/2.0);
    t[2].setPosition(SCREEN_W/2.0, 350);

    t[3].setString("CREDIT");
    t[3].setFont(font);
    t[3].setCharacterSize(25);
    textRec = t[3].getLocalBounds();
    t[3].setOrigin(textRec.width/2.0, textRec.height/2.0);
    t[3].setPosition(SCREEN_W/2.0, 400);

    t[3].setString("QUIT");
    t[3].setFont(font);
    t[3].setCharacterSize(25);
    textRec = t[3].getLocalBounds();
    t[3].setOrigin(textRec.width/2.0, textRec.height/2.0);
    t[3].setPosition(SCREEN_W/2.0, 400);

    t[selected].setColor(sf::Color::Yellow);
}

void draw(sf::RenderWindow& w, sf::Text* t, int n){
    for(int i=0; i<n; i++){
        w.draw(t[i]);
    }
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
            if(event.type == sf::Event::Closed) window.close();

            if(event.type==sf::Event::KeyPressed){
                switch(event.key.code){
                    case sf::Keyboard::Up : selected = (selected+3)%4; std::cout<<selected<<std::endl;
                    break;

                    case sf::Keyboard::Down : selected = (selected+1)%4; std::cout<<selected<<std::endl;
                }
            }
        }

        sf::Font font1, font2;
        font1.loadFromFile("font/impact.ttf");
        sf::Text t[3];
        sf::Text t2[5];
        printTitles(t, 3, font1);
        font2.loadFromFile("font/Minecraft.ttf");
        printOptions(t2, 5, font2);

        window.draw(bg);
        draw(window, t, 3);
        draw(window, t2, 5);
        window.display();
    }

    return 0;
}
