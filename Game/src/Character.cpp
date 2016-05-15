#include "Character.h"

Character::Character()
{
    //default constructor
}

Character::Character(int id, const sf::FloatRect box, const sf::Vector2f speed, int hp, Attack& a, bool vulnerable):TouchableObject(id, box)

{
    this->speed=speed;
    this->hp=hp;
    hpMax=hp;
    *atq=a;
    this->vulnerable = vulnerable;
}

Character::~Character()
{
    //dtor
}

void Character::setHp(int val){
    if(val<hpMax) hp = val;
    else hp=hpMax;
}

int Character::attack(TouchableObject& target)
{
    return 0;
}

int Character::hurt(int damage){
    hp-=damage;

    return hp;
}

bool Character::isDead(){
    if(hp<=0) return true;
    else return false;
}

void Character::print(){
    std::cout<<"[Character "<<id<<"] "<<std::endl;
    std::cout<<"    Hitbox ["<<hitbox.width<<","<<hitbox.height<<"] "<<std::endl;
    std::cout<<"    Speed ["<<speed.x<<","<<speed.y<<"] "<<std::endl;
    std::cout<<"    HP ["<<hp<<","<<hpMax<<"] "<<std::endl;
}
