#include "Pickable.h"

Pickable::Pickable(int id, const sf::IntRect box):TouchableObject(id, box)
{
    enable=false;
}

Pickable::~Pickable()
{

}
