#include "Obstacle.h"

Obstacle::Obstacle(): TouchableObject()
{

}

Obstacle::Obstacle(int id, const sf::FloatRect box, int resistance): TouchableObject(id, box)
{
    res=resistance;
    resMax=resistance;
    destructible=true;
}

Obstacle::~Obstacle()
{
    //dtor
}

bool Obstacle::wasDestroyed(){
    if(destructible && res<=0) return true;
    else return false;
}
