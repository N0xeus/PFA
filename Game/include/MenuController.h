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

        enum limit{
            MAIN_LIMIT = 5,
            OP_LIMIT = 3,
            SC_LIMIT = 5,
            CR_LIMIT = 6,
        };

        enum state{
            //Main menu
            MAIN_PLAY = 0,
            MAIN_OPTIONS = 1,
            MAIN_SCORES = 2,
            MAIN_CREDITS = 3,
            MAIN_QUIT = MAIN_LIMIT-1,

            //Options menu
            OP_DIFFICULTY = 0,
            OP_MUSIC = 1,
            OP_BACK = OP_LIMIT-1,

            //Scores and credits menu
            SC_BACK = SC_LIMIT-1,
            CR_BACK = CR_LIMIT-1
        };

        MenuController();
        virtual ~MenuController();
        static void printTitles(sf::Text*, int, sf::Font&, int, int);
        static void printOptions(std::string* s, sf::Text* t, int n, sf::Font& font, int sc_width, int sc_height, int selection);

    protected:

    private:
};

#endif // MENUCONTROLLER_H
