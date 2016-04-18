#ifndef CHARACTER_H
#define CHARACTER_H

#include <TouchableObject.h>


class Character : public TouchableObject
{
    public:
        Character();
        virtual ~Character();

        int Gethp() { return hp; }
        void Sethp(int val) { hp = val; }
        int Getspeed() { return speed; }
        void Setspeed(int val) { speed = val; }
        int Getjump() { return jump; }
        void Setjump(int val) { jump = val; }
        int Getvulnerable() { return vulnerable; }
        void Setvulnerable(int val) { vulnerable = val; }
        bool attack(TouchableObject to_1);

    protected:

    private:
        int hp;
        int speed;
        int jump;
        int vulnerable;
};

#endif // CHARACTER_H
