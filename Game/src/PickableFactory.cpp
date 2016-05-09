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

Pickable* PickableFactory::createPickable(sf::Vector2i screen, sf::Vector2i pos, sf::Time t){
    Pickable* p=NULL;
    int r1;
    int r2;

    if(t-lastTime>=drop_frequency){
        std::srand(std::time(0));
        r1=std::rand()%2;
        if(r1==0){
            r1=rand()%screen.x/2;
            r2=rand()%screen.y/2;
            p = new Bonus(lastId+1, sf::IntRect(pos+sf::Vector2i(r1, r2), sf::Vector2i(100,100)));
        }else{
            r1=rand()%screen.x/2;
            r2=rand()%screen.y/2;
            p = new Life(lastId+1, sf::IntRect(pos+sf::Vector2i(r1, r2), sf::Vector2i(100,100)));
        }
        lastId++;
        lastTime=t;
    }

    return p;
}
