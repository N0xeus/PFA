#ifndef TOUCHABLEOBJECT_H
#define TOUCHABLEOBJECT_H

#include <SFML/Graphics/Rect.hpp>

class TouchableObject
{
    public:
        TouchableObject(int id, const sf::Rect<float> box);
        virtual ~TouchableObject();

        int getId() { return id; }
        sf::Rect<float> getHitbox() { return hitbox; }

        bool intersects(TouchableObject& to);
        void print();

    protected:
        int id;
        sf::Rect<float> hitbox;

    private:

};

#endif // TOUCHABLEOBJECT_H
