#include <iostream>
#include "TouchableObject.h"

TouchableObject::TouchableObject()
{

}

TouchableObject::TouchableObject(int id, const sf::FloatRect box)
{
    this->id=id;
    this->hitbox=box;
    this->pos = Point(box.left+box.width/2,box.top+box.height/2);
}

TouchableObject::~TouchableObject()
{
    //dtor
}

void TouchableObject::setPosition(float x, float y){
    hitbox.left=x;
    hitbox.top=y;
}

bool TouchableObject::intersects(TouchableObject& to){
    return hitbox.intersects(to.getHitbox());
}
