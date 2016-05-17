#include "GameController.h"
#include "HtH.h"

#define GRAVITY 20
#define SCREEN_W 800
#define SCREEN_H 600

GameController::GameController(sf::RenderWindow &window)
{
    w=&window;
    view.reset(sf::FloatRect(0,0,SCREEN_W,SCREEN_H));
    HtH a(300,sf::FloatRect(10,10,0,FLOOR_Y),1,1);
    hero=Hero(0,sf::FloatRect(0,FLOOR_Y-200,100,100),sf::Vector2f(0,0),100, a, 3,0);

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
    bool a=false;
    bool b=false;
    int j;
    for(int i=0; i<NB_PLAT; i++){
        a=hero.getY()+hero.getHitbox().height>=obstacleTab[i].getY();
        a=a&&hero.getY()+hero.getHitbox().height<=obstacleTab[i].getY()+obstacleTab[i].getHitbox().height;
        b=obstacleTab[i].intersects(hero);
        if(b){
            j=i;
            break;
        }
    }
    if(b) printf("OK b ");
    if(a) printf("OK a ");
    //b=b&&(!hero.getY()>obstacleTab[j].getY());
    if(a && b && hero.getSpeed().y>0){
        hero.setSpeedY(0);
        hero.setState(Hero::IDLE);
        hero.setPosition(hero.getX(),obstacleTab[j].getY()-hero.getHitbox().height);
        printf("OK%d\n", j);
    }else hero.setState(Hero::JUMP);

    if(hero.getX()<0) hero.setPosition(0,hero.getY());
    if(hero.getX()>FLOOR_LENGTH-hero.getHitbox().width) hero.setPosition(FLOOR_LENGTH-hero.getHitbox().width,hero.getY());
}

void GameController::changeView(){
    if(hero.getX()>SCREEN_W/2 && hero.getX()<FLOOR_LENGTH-SCREEN_W/2)view.setCenter(hero.getX(), SCREEN_H/2);
    w->setView(view);
}

void GameController::draw(){
    for(int i=0; i<NB_PLAT; i++){
        w->draw(obstacle_display[i]);
    }

   w->draw(hero_display);
}

void GameController::moveHero(sf::Vector2f v){
    hero.setSpeedX(v.x);
}

void GameController::gravity(float val){
    hero.setSpeedY(hero.getSpeed().y+val);
}

void GameController::jumpHero(float val){
    if(hero.getState()!=Hero::JUMP){
        hero.setSpeedY(val);
        hero.setState(Hero::JUMP);
        printf("JUMP\n");
    }
}

void GameController::update(float time){
    gravity(GRAVITY*time);
    hero.move();
    collisionHero();
    changeView();

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
