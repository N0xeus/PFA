#ifndef ENEMY_H
#define ENEMY_H

#include <Character.h>


class Enemy : public Character
{
    public:
        Enemy();
        virtual ~Enemy();

        int Gettype() { return type; }
        void Settype(int val) { type = val; }
        int Getrange() { return range; }
        void Setrange(int val) { range = val; }


    protected:

    private:
        int type;
        int range;
};

#endif // ENEMY_H
