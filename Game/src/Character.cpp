#include "Character.h"
#include <iostream>

Character::Character(int id, const sf::Rect<float> box, const sf::Vector2f speed, int hp):TouchableObject(id, box)
{
    this->speed=speed;
    this->hp=hp;
    this->hpMax=hp;
}

Character::~Character()
{
    //dtor
}

int Character::attack(TouchableObject& target)
{
    return 0;
}

bool Character::isDead(){
    if(hpMax-hp<=0) return true;
    else return false;
}

int hurt(int damage){
    hp-=damage;
    return hp;
}

void Character::print(){
    std::cout<<"[Character "<<id<<"] "<<std::endl;
    std::cout<<"    Hitbox ["<<hitbox.width<<","<<hitbox.height<<"] "<<std::endl;
    std::cout<<"    Speed ["<<speed.x<<","<<speed.y<<"] "<<std::endl;
    std::cout<<"    HP ["<<hp<<","<<hpMax<<"] "<<std::endl;
}
