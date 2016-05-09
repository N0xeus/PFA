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
    Projectile* p=NULL;

    if(isReady(t)){
        p = new Projectile(id, sf::IntRect(hitbox.left, hitbox.top,100,100), power, 0, sf::Vector2f(10,0));
    }

    return p;
}
