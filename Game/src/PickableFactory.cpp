#include "PickableFactory.h"
#include "Bonus.h"
#include "Life.h"
#include <iostream>
#include <ctime>

PickableFactory::PickableFactory(float frequency)
{
    drop_frequency=sf::seconds(frequency);
    lastTime = sf::seconds(0);
    lastId=100;
}

PickableFactory::~PickableFactory()
{
    //dtor
}

Pickable* PickableFactory::createPickable(sf::Vector2f screen, sf::Vector2f pos, sf::Time t){
    Pickable* p=NULL;
    int r1;
    int r2;

    if(t-lastTime>=drop_frequency){
        std::srand(std::time(0));
        r1=std::rand()%2;
        if(r1==0){
            r1=rand()%(int)screen.x/2;
            r2=rand()%(int)screen.y/2;
            p = new Bonus(lastId+1, sf::FloatRect(pos+sf::Vector2f(r1, r2), sf::Vector2f(100,100)));
        }else{
            r1=rand()%(int)screen.x/2;
            r2=rand()%(int)screen.y/2;
            p = new Life(lastId+1, sf::FloatRect(pos+sf::Vector2f(r1, r2), sf::Vector2f(100,100)));
        }
        lastId++;
        lastTime=t;
    }

    return p;
}
