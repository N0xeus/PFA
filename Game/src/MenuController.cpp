#include "MenuController.h"

MenuController::MenuController()
{

}

MenuController::~MenuController()
{
    //dtor
}

void MenuController::printTitles(sf::Text* t, int n, sf::Font& font, int sc_width, int sc_heigth){
    if(n!=3) return;
    t[0].setString("LGGP");
    t[0].setFont(font);
    t[0].setCharacterSize(150);
    t[0].setStyle(sf::Text::Bold);
    sf::FloatRect textRec = t[0].getLocalBounds();
    t[0].setOrigin(textRec.width/2.0, textRec.height/2.0);
    t[0].setPosition(sc_width/2.0, sc_heigth/8.0);

    t[1].setString("PROJECT");
    t[1].setFont(font);
    t[1].setCharacterSize(50);
    t[1].setStyle(sf::Text::Bold);
    textRec = t[1].getLocalBounds();
    t[1].setOrigin(textRec.width/2.0, textRec.height/2.0);
    t[1].setPosition(sc_width/2.0, 13*sc_heigth/16.0);

    t[2].setString("(C) DEVELOPED BY LEO GARREAU & GAETAN PUGET");
    t[2].setFont(font);
    t[2].setCharacterSize(25);
    textRec = t[2].getLocalBounds();
    t[2].setOrigin(textRec.width/2.0, textRec.height/2.0);
    t[2].setPosition(sc_width/2.0, 15*sc_heigth/16.0);
}

void MenuController::printOptions(std::string* s, sf::Text* t, int n, sf::Font& font, int sc_width, int sc_heigth, int selection){
    sf::FloatRect textRec;
    for(int i=0;i<n;i++){
        t[i].setString(s[i]);
        t[i].setFont(font);
        t[i].setCharacterSize(25);
        textRec = t[i].getLocalBounds();
        t[i].setOrigin(textRec.width/2.0, textRec.height/2.0);
        t[i].setPosition(sc_width/2.0, 200+i*50);
    }

    t[selection].setColor(sf::Color::Yellow);
}
