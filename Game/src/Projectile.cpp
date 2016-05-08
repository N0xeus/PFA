#include "Projectile.h"

Projectile::Projectile(int id, const sf::IntRect box, int damage, float atqSpeed, const sf::Vector2f mvtSpeed):Attack(id,box,damage,atqSpeed)
{
    ms=mvtSpeed;
}

Projectile::~Projectile()
{
    //dtor
}
