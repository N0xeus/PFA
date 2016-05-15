#include "Enemy.h"

Enemy::Enemy()
{

}

Enemy::Enemy(int id, const sf::FloatRect box, const sf::Vector2f speed, int hp, Attack& a, bool vulnerable, int type, int sight, int range):Character(id, box, speed, hp, a, vulnerable)
{
    this->type = type;
    this->sight = sight;
    this->range = range;
}

float Enemy::distance(int x1, int y1, int x2, int y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

bool Enemy::canAttack(int timeSinceLastAttack)
{
    if(this->atq.getSpeed()>timeSinceLastAttack)
        return false;
    return true;
}

bool Enemy::canSeePlayer(Hero hero)
{
    if(distance(hero.getPosX(),hero.getPosY(), this->getHitbox().left+this->getHitbox().width/2, this->getHitbox().top+this->getHitbox().height/2))
}


virtual int Enemy::attack(TouchableObject& target);

Enemy::~Enemy()
{
    //dtor
}
