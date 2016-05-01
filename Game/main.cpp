#include <iostream>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "MenuController.h"

using namespace std;

//Width and heigth
#define SCREEN_W 800
#define SCREEN_H 600

//Selected options and current menu
int selected=0;
int current_menu=0;

void draw(sf::RenderWindow& w, sf::Text* t, int n){
    for(int i=0; i<n; i++){
        w.draw(t[i]);
    }
}

int main(void){
    //800x600 window entitled LGGP Project with a fix size
    //Screen frame rate limited at 60Hz
    sf::RenderWindow window(sf::VideoMode(SCREEN_W,SCREEN_H), "LGGP Project", sf::Style::Close);
    window.setFramerateLimit(60);

    //Scott head selected as icon for the window
    sf::Image icon;
    icon.loadFromFile("img/icon.png");
    window.setIcon(100,100,icon.getPixelsPtr());

    //Select the background
    sf::Texture bgt;
    bgt.loadFromFile("img/background.jpg");
    sf::RectangleShape bg = sf::RectangleShape(sf::Vector2f(800,600));
    bg.setTexture(&bgt);

    //Clear the window with a black screen
    window.clear(sf::Color::Black);

    sf::Event event;
    int limit;
    sf::Font font1, font2;
    font1.loadFromFile("font/impact.ttf");
    font2.loadFromFile("font/Minecraft.ttf");
    sf::Text* titles;
    sf::Text* options;
    string* s;

    while(window.isOpen()){
        switch(current_menu){
            case MenuController::MAIN_ID :
                limit=MenuController::MAIN_LIMIT;

                //Window is listening events
                while(window.pollEvent(event)){
                    //Window closed
                    if(event.type==sf::Event::Closed) window.close();

                    //Key pressed
                    if(event.type==sf::Event::KeyPressed){
                        switch(event.key.code){
                            case sf::Keyboard::Up : selected = (selected+(limit-1))%limit;
                            break;

                            case sf::Keyboard::Down : selected = (selected+1)%limit;
                            break;

                            case sf::Keyboard::Return :
                                switch(selected){
                                    case MenuController::MAIN_QUIT :
                                        window.close();
                                    break;

                                    case MenuController::MAIN_OPTIONS :
                                        current_menu=MenuController::OP_ID;
                                        selected=0;
                                    break;
                                }
                            break;
                        }
                    }
                }

                //Draw the background
                window.draw(bg);
                //Mark title
                titles=new sf::Text[3];
                MenuController::printTitles(titles, 3, font1, SCREEN_W, SCREEN_H);
                //Mark options
                options = new sf::Text[limit];
                s = new string[limit];
                s[0] = "PLAY";
                s[1] = "OPTIONS";
                s[2] = "SCORES";
                s[3] = "CREDITS";
                s[4] = "QUIT";
                MenuController::printOptions(s, options, 5, font2, SCREEN_W, SCREEN_H, selected);
                //Draw titles and options
                draw(window, titles, 3);
                draw(window, options, limit);

                window.display();
            break;

            case MenuController::OP_ID :
                limit=MenuController::OP_LIMIT;

                //Window is listening events
                while(window.pollEvent(event)){
                    //Window closed
                    if(event.type==sf::Event::Closed) window.close();

                    //Key pressed
                    if(event.type==sf::Event::KeyPressed){
                        switch(event.key.code){
                            case sf::Keyboard::Up : selected = (selected+(limit-1))%limit;
                            break;

                            case sf::Keyboard::Down : selected = (selected+1)%limit;
                            break;

                            case sf::Keyboard::Return :
                                switch(selected){
                                    case MenuController::OP_BACK :
                                        current_menu=MenuController::MAIN_ID;
                                    break;
                                }
                            break;
                        }
                    }
                }
                //Draw the background
                window.draw(bg);
                //Mark title
                MenuController::printTitles(titles, 3, font1, SCREEN_W, SCREEN_H);
                //Mark options
                options = new sf::Text[limit];
                s = new string[limit];
                s[0] = "DIFFICULTY";
                s[1] = "MUSIC";
                s[2] = "BACK";
                MenuController::printOptions(s, options, limit, font2, SCREEN_W, SCREEN_H, selected);
                //Draw titles and options
                draw(window, titles, 3);
                draw(window, options, limit);

                window.display();
            break;
        }
    }

    free(titles);
    free(options);
    free(s);

    return 0;
}
