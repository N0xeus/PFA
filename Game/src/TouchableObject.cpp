#include <iostream>
#include "TouchableObject.h"

TouchableObject::TouchableObject(int id, const sf::IntRect box)
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

void TouchableObject::print(){
    std::cout<<"[TouchableObject "<<id<<"] "<<std::endl;
    std::cout<<"    Hitbox ["<<hitbox.width<<","<<hitbox.height<<"] "<<std::endl;
}
