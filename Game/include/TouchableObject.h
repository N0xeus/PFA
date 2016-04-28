#ifndef TOUCHABLEOBJECT_H
#define TOUCHABLEOBJECT_H

#include <SFML/Graphics/Rect.hpp>

class TouchableObject
{
    public:
        TouchableObject(int id, const sf::IntRect box);
        virtual ~TouchableObject();

        int getId() { return id; }
        sf::IntRect getHitbox() { return hitbox; }

        bool intersects(TouchableObject& to);
        void print();

    protected:
        int id;
        sf::IntRect hitbox;

    private:

};

#endif // TOUCHABLEOBJECT_H
