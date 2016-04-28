#include "Character.h"

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
