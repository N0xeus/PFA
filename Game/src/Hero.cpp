#include "Hero.h"

Hero::Hero()
{
    //ctor
}

Hero::Hero(int id, const sf::FloatRect box, const sf::Vector2f speed, int hp, Attack& a, int lives, int state):Character(id, box, speed, hp, a, vulnerable)
{
    this->lives = lives;
    this->state = state;
}

Hero::~Hero()
{
    //dtor
}
