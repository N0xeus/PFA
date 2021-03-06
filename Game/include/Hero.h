#ifndef HERO_H
#define HERO_H

#include <Character.h>


class Hero : public Character
{
    public:
        Hero();
        Hero(int id, const sf::FloatRect box, const sf::Vector2f speed, int hp, Attack& a, int lives, int state);
        virtual ~Hero();

        int Getlives() { return lives; }
        void Setlives(int val) { lives = val; }
        int getState() { return state; }
        void setState(int val) { state = val; }

        enum s{
            IDLE=0,
            JUMP=1,
        };

    protected:

    private:
        int lives;
        int state;
};

#endif // HERO_H
