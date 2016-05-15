#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <SFML/Graphics.hpp>
#include "Obstacle.h"

static const int NB_PLAT=5;
static const int FLOOR_LENGTH=1600;
static const int FLOOR_Y=590;

class GameController
{
    public:
        GameController(sf::RenderWindow &window);
        virtual ~GameController();

        void draw();
        void update();
    protected:

    private:
        sf::RenderWindow* w;
        Obstacle obstacleTab[NB_PLAT];
        sf::RectangleShape obstacle_display[NB_PLAT];
};

#endif // GAMECONTROLLER_H
