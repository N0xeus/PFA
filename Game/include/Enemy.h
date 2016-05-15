#ifndef ENEMY_H
#define ENEMY_H

#include <Character.h>
#include <Hero.h>
#include <cmath>
#include <SFML/System/Time.hpp>


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
        int Getsight() { return sight; }
        void Setsight(int val) { sight = val; }
        float distance(int x1, int y1, int x2, int y2);
        bool canAttack(sf::Time timeSinceLastAttack);
        bool canSeePlayer(Hero hero);


    protected:

    private:
        int type;
        // type 1: normal HtH enemy
        // type 2: normal projectile enemy
        // type 3 and more: bosses
        int sight;
        int range;
};

#endif // ENEMY_H
