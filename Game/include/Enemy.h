#ifndef ENEMY_H
#define ENEMY_H

#include <Character.h>
#include <cmath>


class Enemy : public Character
{
    public:
        Enemy();
        Enemy(int id, const sf::FloatRect box, const sf::Vector2f speed, int hp, Attack& a, bool vulnerable, int type, int sight, int range);
        virtual ~Enemy();

        int Gettype() { return type; }
        void Settype(int val) { type = val; }
        int Getrange() { return range; }
        void Setrange(int val) { range = val; }
        float distance(int x1, int y1, int x2, int y2);
        bool canAttack(int timeSinceLastAttack);
        bool canSeePlayer();
        virtual int attack(TouchableObject& target);


    protected:

    private:
        int type;
        int sight;
        int range;
};

#endif // ENEMY_H
