#include "Enemy.h"

Enemy::Enemy()
{

}

Enemy::Enemy(int id, const sf::FloatRect box, const sf::Vector2f speed, int hp, Attack& a, int type, int sight, int range):Character(id, box, speed, hp, a)
{
    this->type = type;
    this->sight = sight;
    this->range = range;
}

Enemy::Enemy(Enemy& e)
{
    this->id = e.id;
    this->hitbox = e.hitbox;
    this->speed = e.speed;
    this->hp = e.hp;
    this->hpMax = e.hpMax;
    this->vulnerable = e.vulnerable;
    this->type = e.type;
    this->sight = e.sight;
    this->range = e.range;
}

float Enemy::distance(int x1, int y1, int x2, int y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

bool Enemy::canAttack(sf::Time timeSinceLastAttack)
{
    return this->atq->isReady(timeSinceLastAttack);
}

//bool Enemy::canSeePlayer(Hero hero)
//{
//    if(distance(hero.GetposX(),hero.GetposY(), this->getHitbox().left+this->getHitbox().width/2, this->getHitbox().top+this->getHitbox().height/2) < this->Getsight())
//        return true;
//    return false;
//}


//int Enemy::attack(TouchableObject& target)
//{
//    switch(this->Gettype())
//    {
//        case 1:
//            if(distance(hero.GetposX(),hero.GetposY(), this->getHitbox().left+this->getHitbox().width/2, this->getHitbox().top+this->getHitbox().height/2) < this->Getrange())
//                target->
//    }
//}

Enemy::~Enemy()
{
    //dtor
}
