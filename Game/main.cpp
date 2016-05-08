#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Character.h"
#include "MenuController.h"

using namespace std;

//Width and height
#define SCREEN_W 800
#define SCREEN_H 600

//Selected options and current menu
int selected=0;
int current_menu=0;
//Difficulty and music state
int difficulty=0;
bool music_state=true;

//Draw texts in the window
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

    //Music by Toby Fox
    sf::Music music;
    music.openFromFile("audio/menu.wav");
    music.setLoop(true);
    music.setVolume(50.);
    music.play();

    //Validation song
    sf::SoundBuffer buffer;
    buffer.loadFromFile("audio/validation.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);

    //Clear the window with a black screen
    window.clear(sf::Color::Black);

    sf::Event event;
    int limit;
    sf::Font font1, font2;
    font1.loadFromFile("font/impact.ttf");
    font2.loadFromFile("font/Minecraft.ttf"); //Craftron Gaming
    sf::Text* titles;
    sf::Text* options;
    ifstream scores_file("scores.txt");
    string main_string[MenuController::MAIN_LIMIT] = {"PLAY", "OPTIONS", "SCORES", "CREDITS", "QUIT"};
    string options_string[MenuController::OP_LIMIT]= {"DIFFICULTY : NOOB", "MUSIC : ON", "BACK"};
    string scores_string[MenuController::SC_LIMIT]= {"", "", "", "", "BACK"};
    string credits_string[MenuController::CR_LIMIT]= {"DEVELOPER : LEO GARREAU",
                                                        "DEVELOPER : GAETAN PUGET",
                                                        "SPRITES : MAVERICK PK",
                                                        "MUSIC : TOBY FOX",
                                                        "FONT : CRAFTRON GAMING",
                                                        "BACK"
                                                    };

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
                            //Previous selection
                            case sf::Keyboard::Up : selected = (selected+(limit-1))%limit;
                            break;

                            //Next selection
                            case sf::Keyboard::Down : selected = (selected+1)%limit;
                            break;

                            //Press ENTER
                            case sf::Keyboard::Return : sound.play();
                                switch(selected){
                                    //Quit
                                    case MenuController::MAIN_QUIT :
                                        window.close();
                                    break;

                                    //Options menu
                                    case MenuController::MAIN_OPTIONS :
                                        current_menu=MenuController::OP_ID;
                                        selected=0;
                                    break;

                                    //Scores menu
                                    case MenuController::MAIN_SCORES :
                                        current_menu=MenuController::SC_ID;
                                        selected=0;
                                    break;

                                    //Credits menu
                                    case MenuController::MAIN_CREDITS :
                                        current_menu=MenuController::CR_ID;
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
                MenuController::printOptions(main_string, options, limit, font2, SCREEN_W, SCREEN_H, selected);
                //Draw titles and options
                draw(window, titles, 3);
                draw(window, options, limit);

                window.display();
            break;

            //Options menu
            case MenuController::OP_ID :
                limit=MenuController::OP_LIMIT;

                //Window is listening events
                while(window.pollEvent(event)){
                    //Window closed
                    if(event.type==sf::Event::Closed) window.close();

                    //Key pressed
                    if(event.type==sf::Event::KeyPressed){
                        switch(event.key.code){
                            //Previous selection
                            case sf::Keyboard::Up : selected = (selected+(limit-1))%limit;
                            break;

                            //Next selection
                            case sf::Keyboard::Down : selected = (selected+1)%limit;
                            break;

                            case sf::Keyboard::Left :
                                switch(selected){
                                    //Change difficulty
                                    case MenuController::OP_DIFFICULTY :
                                        if(difficulty==2){
                                            difficulty--;
                                            options_string[MenuController::OP_DIFFICULTY]="DIFFICULTY : NORMAL";
                                            sound.play();
                                        }else if(difficulty==1){
                                            difficulty--;
                                            options_string[MenuController::OP_DIFFICULTY]="DIFFICULTY : NOOB";
                                            sound.play();
                                        }
                                    break;

                                    //Change music state
                                    case MenuController::OP_MUSIC :
                                        if(!music_state){
                                            music_state=!music_state;
                                            options_string[MenuController::OP_MUSIC]="MUSIC : ON";
                                            music.play();
                                        }
                                    break;
                                }
                            break;

                            case sf::Keyboard::Right :
                                switch(selected){
                                    //Change difficulty
                                    case MenuController::OP_DIFFICULTY :
                                        if(difficulty==0){
                                            difficulty++;
                                            options_string[MenuController::OP_DIFFICULTY]="DIFFICULTY : NORMAL";
                                            sound.play();
                                        }else if(difficulty==1){
                                            difficulty++;
                                            options_string[MenuController::OP_DIFFICULTY]="DIFFICULTY : TRY HARDER";
                                            sound.play();
                                        }
                                    break;

                                    //Change music state
                                    case MenuController::OP_MUSIC :
                                        if(music_state){
                                            music_state=!music_state;
                                            options_string[MenuController::OP_MUSIC]="MUSIC : OFF";
                                            music.pause();
                                        }
                                    break;
                                }
                            break;

                            //Press ENTER
                            case sf::Keyboard::Return :
                                switch(selected){
                                    //Go to Main menu
                                    case MenuController::OP_BACK :
                                        current_menu=MenuController::MAIN_ID;
                                        selected=0;
                                        sound.play();
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
                MenuController::printOptions(options_string, options, limit, font2, SCREEN_W, SCREEN_H, selected);
                //Draw titles and options
                draw(window, titles, 3);
                draw(window, options, limit);

                window.display();
            break;

            //Scores menu
            case MenuController::SC_ID :
                limit=MenuController::SC_LIMIT;

                //Window is listening events
                while(window.pollEvent(event)){
                    //Window closed
                    if(event.type==sf::Event::Closed) window.close();

                    //Key pressed
                    if(event.type==sf::Event::KeyPressed){
                        switch(event.key.code){
                            //Previous selection
                            case sf::Keyboard::Up : selected = (selected+(limit-1))%limit;
                            break;

                            //Next selection
                            case sf::Keyboard::Down : selected = (selected+1)%limit;
                            break;

                            //Press ENTER
                            case sf::Keyboard::Return :
                                switch(selected){
                                    //Go to Main menu
                                    case MenuController::SC_BACK :
                                        current_menu=MenuController::MAIN_ID;
                                        selected=0;
                                        sound.play();
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
                for(int i=0;i<limit-1;i++) getline(scores_file, scores_string[i]);
                MenuController::printOptions(scores_string, options, limit, font2, SCREEN_W, SCREEN_H, selected);
                //Draw titles and options
                draw(window, titles, 3);
                draw(window, options, limit);

                window.display();
            break;

            //Credits menu
            case MenuController::CR_ID :
                limit=MenuController::CR_LIMIT;

                //Window is listening events
                while(window.pollEvent(event)){
                    //Window closed
                    if(event.type==sf::Event::Closed) window.close();

                    //Key pressed
                    if(event.type==sf::Event::KeyPressed){
                        switch(event.key.code){
                            //Previous selection
                            case sf::Keyboard::Up : selected = (selected+(limit-1))%limit;
                            break;

                            //Next selection
                            case sf::Keyboard::Down : selected = (selected+1)%limit;
                            break;

                            //Press ENTER
                            case sf::Keyboard::Return :
                                switch(selected){
                                    //Go to Main menu
                                    case MenuController::CR_BACK :
                                        current_menu=MenuController::MAIN_ID;
                                        selected=0;
                                        sound.play();
                                    break;
                                }
                            break;
                        }
                    }
                }
                //Draw the background
                window.draw(bg);
                //Mark options
                options = new sf::Text[limit];
                MenuController::printOptions(credits_string, options, limit, font2, SCREEN_W, SCREEN_H, selected);
                //Draw titles and options
                draw(window, options, limit);

                window.display();
            break;
        }
    }

    free(titles);
    free(options);

    return 0;
}
