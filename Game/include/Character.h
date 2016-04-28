#ifndef CHARACTER_H
#define CHARACTER_H

#include <TouchableObject.h>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

class Character : public TouchableObject
{
    public:
        Character(int id, const sf::Rect<float>, const sf::Vector2f speed, int hp);
        virtual ~Character();

        int getHp() { return hp; }
        void setHp(int val) { hp = val; }
        sf::Vector2f getSpeed() { return speed; }
        void setSpeedX(float val) { speed.x = val; }
        void setSpeedY(float val) { speed.y = val; }
        bool isVulnerable() { return vulnerable; }
        void setVulnerable(bool val){vulnerable = val;}

        int attack(TouchableObject& target);
        bool isDead();
        int hurt(int damage);

        void print();

    protected:

    private:
        int hp;
        int hpMax;
        sf::Vector2f speed;
        bool vulnerable;
};

#endif // CHARACTER_H
