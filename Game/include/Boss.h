#ifndef BOSS_H
#define BOSS_H

#include <Enemy.h>


class Boss : public Enemy
{
    public:
        Boss();
        virtual ~Boss();

        int Getphase() { return phase; }
        void Setphase(int val) { phase = val; }

    protected:

    private:
        int phase;
};

#endif // BOSS_H
