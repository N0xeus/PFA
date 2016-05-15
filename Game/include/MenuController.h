#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

////////////////////////////////////////////////////////////
// Header
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

////////////////////////////////////////////////////////////
/// \brief Menu controller to choose different screen or modify options
///
////////////////////////////////////////////////////////////
class MenuController
{
    public:
        ////////////////////////////////////////////////////////////
        // Member data
        ////////////////////////////////////////////////////////////
        enum id{                        /// Screen identifiers
            MAIN_ID = 0,
            PLAY_ID = 1,
            OP_ID = 2,
            SC_ID = 3,
            CR_ID = 4,
        };

        enum limit{                     /// Limit numbers of possibilities
            MAIN_LIMIT = 5,
            OP_LIMIT = 3,
            SC_LIMIT = 5,
            CR_LIMIT = 6,
        };

        enum state{                     /// Possibility identifiers for each screen
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

        ////////////////////////////////////////////////////////////
        /// \brief Constructor
        ///
        ////////////////////////////////////////////////////////////
        MenuController();

        ////////////////////////////////////////////////////////////
        /// \brief Destructor
        ///
        ////////////////////////////////////////////////////////////
        virtual ~MenuController();

        ////////////////////////////////////////////////////////////
        /// \brief Print options on the screen
        ///
        /// \param s String array to put into displayable text
        /// \param t Text array to display
        /// \param n Size of arrays
        /// \param font Font to use
        /// \param sc_width Screen width
        /// \param sc_height Screen height
        /// \param selection Selectionned option
        ///
        /// Initiate displayable text with string
        ///
        /// \see sf::Text
        /// \see sf::Font
        ///
        ////////////////////////////////////////////////////////////
        static void printOptions(std::string* s, sf::Text* t, int n, sf::Font& font, int sc_width, int sc_height, int selection);

        ////////////////////////////////////////////////////////////
        /// \brief Print titles on the screen
        ///
        /// \param t Text array to display
        /// \param n Size of arrays
        /// \param font Font to use
        /// \param sc_width Screen width
        /// \param sc_height Screen height
        ///
        /// Initiate displayable text with titles
        ///
        /// \see sf::Text
        /// \see sf::Font
        ///
        ////////////////////////////////////////////////////////////
        static void printTitles(sf::Text* t, int n, sf::Font& font, int sc_width, int sc_height);

    protected:

    private:
};

#endif // MENUCONTROLLER_H
