#include "GameController.h"

GameController::GameController(sf::RenderWindow &window)
{
    w=&window;



    int obsID=200;
    int i=0;
    obstacleTab[i]=Obstacle(obsID+i, sf::FloatRect(FLOOR_LENGTH,10,0,FLOOR_Y), 0);
    obstacleTab[i++].setDestructible(false);

    obstacleTab[i]=Obstacle(obsID+i, sf::FloatRect(200,10,200,FLOOR_Y-100), 0);
    obstacleTab[i++].setDestructible(false);

    obstacleTab[i]=Obstacle(obsID+i, sf::FloatRect(200,10,400,FLOOR_Y-200), 0);
    obstacleTab[i++].setDestructible(false);

    obstacleTab[i]=Obstacle(obsID+i, sf::FloatRect(200,10,200,FLOOR_Y-300), 0);
    obstacleTab[i++].setDestructible(false);

    obstacleTab[i]=Obstacle(obsID+i, sf::FloatRect(500,10,500,FLOOR_Y-400), 0);
    obstacleTab[i++].setDestructible(false);
    for(int i=0; i<NB_PLAT; i++){
        sf::FloatRect h=obstacleTab[i].getHitbox();
        obstacle_display[i]=sf::RectangleShape(sf::Vector2f(h.left, h.top));
        obstacle_display[i].setPosition(sf::Vector2f(h.width, h.height));
    }
    obstacle_display[0].setFillColor(sf::Color(155,155,155,255));
    obstacle_display[1].setFillColor(sf::Color(255,255,255,255));


}

void GameController::draw(){
    for(int i=0; i<NB_PLAT; i++){
        w->draw(obstacle_display[i]);
    }
}

void GameController::update(){

}

GameController::~GameController()
{
    //dtor
}
