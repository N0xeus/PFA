#include "Pickable.h"

Pickable::Pickable(int id, const sf::FloatRect box):TouchableObject(id, box)
{
    enable=false;
}

Pickable::~Pickable()
{

}
