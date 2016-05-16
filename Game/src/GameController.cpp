#include "GameController.h"
#include "HtH.h"

GameController::GameController(sf::RenderWindow &window)
{
    w=&window;
    HtH a(300,sf::FloatRect(10,10,0,FLOOR_Y),1,1);
    hero=Hero(0,sf::FloatRect(0,FLOOR_Y-150,100,100),sf::Vector2f(0,0),100, a, 3,0);

    int obsID=200;
    int i=0;
    obstacleTab[i]=Obstacle(obsID+i, sf::FloatRect(0,FLOOR_Y,FLOOR_LENGTH,10), 0);
    obstacleTab[i++].setDestructible(false);

    obstacleTab[i]=Obstacle(obsID+i, sf::FloatRect(200,FLOOR_Y-100,200,10), 0);
    obstacleTab[i++].setDestructible(false);

    obstacleTab[i]=Obstacle(obsID+i, sf::FloatRect(400,FLOOR_Y-200,200,10), 0);
    obstacleTab[i++].setDestructible(false);

    obstacleTab[i]=Obstacle(obsID+i, sf::FloatRect(200,FLOOR_Y-300,200,10), 0);
    obstacleTab[i++].setDestructible(false);

    obstacleTab[i]=Obstacle(obsID+i, sf::FloatRect(500,FLOOR_Y-400,500,10), 0);
    obstacleTab[i++].setDestructible(false);
}

void GameController::collisionHero(){
    bool b=false;
    int j;
    for(int i; i<NB_PLAT; i++){
        b=hero.intersects(obstacleTab[i]);
        if(b){
            j=i;
            break;
        }
    }

    if(b){
        hero.setSpeedY(0);
        hero.setPosition(hero.getX(),obstacleTab[j].getY()-hero.getHitbox().height);
    }
}

void GameController::draw(){
    for(int i=0; i<NB_PLAT; i++){
        w->draw(obstacle_display[i]);
    }

   w->draw(hero_display);
}

void GameController::moveHero(sf::Vector2f v){
    hero.setSpeedX(v.x);
    hero.setSpeedY(v.y);
    hero.move();
}

void GameController::gravity(){
    moveHero(sf::Vector2f(0,10));
}

void GameController::update(){
    gravity();
    collisionHero();

    for(int i=0; i<NB_PLAT; i++){
        sf::FloatRect h=obstacleTab[i].getHitbox();
        obstacle_display[i]=sf::RectangleShape(sf::Vector2f(h.width, h.height));
        obstacle_display[i].setPosition(sf::Vector2f(h.left, h.top));
    }
    obstacle_display[0].setFillColor(sf::Color(155,155,155,255));
    obstacle_display[1].setFillColor(sf::Color(255,255,255,255));

    hero_display=sf::RectangleShape(sf::Vector2f(hero.getHitbox().width, hero.getHitbox().height));
    hero_display.setPosition(sf::Vector2f(hero.getX(), hero.getY()));
}

GameController::~GameController()
{
    //dtor
}
