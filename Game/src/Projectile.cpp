#include "Projectile.h"

Projectile::Projectile(int id, const sf::IntRect box, int damage, float atqSpeed, const sf::Vector2f mvtSpeed):Attack(id,box,damage,atqSpeed)
{
    ms=mvtSpeed;
}

Projectile::~Projectile()
{
    //dtor
}


Projectile* Projectile::create(sf::Time t){
    Projectile* p=nullptr;

    if(isReady(t)){
        p = new Projectile(id, sf::Vector2i(100,100), power, 0, sf::Vector2f(10,0));
    }

    return p;
}
