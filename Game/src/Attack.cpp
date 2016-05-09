#include "Attack.h"

Attack::Attack(int id, const sf::IntRect box, int damage, float atqSpeed):TouchableObject(id, box)
{
    power=damage;
    speed=sf::seconds(atqSpeed);
    previousHit=sf::seconds(0);
    enable=false;
}

Attack::~Attack()
{
    //dtor
}

bool Attack::isReady(sf::Time t){
    sf::Time diff = t - previousHit;
    if(diff>=speed){
        setEnable(true);
        previousHit=t;
    }else setEnable(false);

    return enable;
}
