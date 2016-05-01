#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class MenuController
{
    public:
        enum id{
            MAIN_ID = 0,
            OP_ID = 1,
            SC_ID = 2,
            CR_ID = 3,
        };

        //Main menu
        enum main{
            MAIN_PLAY = 0,
            MAIN_OPTIONS = 1,
            MAIN_SCORES = 2,
            MAIN_CREDITS = 3,
            MAIN_QUIT = 4,
            MAIN_LIMIT = 5
        };

        //Options menu
        const int OP_DIFFICULTY = 5;
        const int OP_MUSIC = 6;
        const int OP_BACK = 7;
        const int OP_LIMIT = 3;

        //Scores menu
        const int SC_LIMIT = 5;

        //Credits menu
        const int CR_LIMIT = 3;

        MenuController();
        virtual ~MenuController();
        static void printTitles(sf::Text*, int, sf::Font&, int, int);
        static void printOptions(std::string* s, sf::Text* t, int n, sf::Font& font, int sc_width, int sc_heigth, int selection);

    protected:

    private:
};

#endif // MENUCONTROLLER_H
