#include <iostream>
#include "TouchableObject.h"

TouchableObject::TouchableObject()
{

}

TouchableObject::TouchableObject(int id, const sf::FloatRect box)
{
    this->id=id;
    this->hitbox=box;
}

TouchableObject::~TouchableObject()
{
    //dtor
}

bool TouchableObject::intersects(TouchableObject& to){
    return hitbox.intersects(to.getHitbox());
}
