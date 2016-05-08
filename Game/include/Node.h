#ifndef NODE_H
#define NODE_H

#include "Point.h"

class Node
{
    public:
        Node();
        Node(Point);
        virtual ~Node();

        float Getcout_g() { return cout_g; }
        void Setcout_g(float val) { cout_g = val; }
        float Getcout_h() { return cout_h; }
        void Setcout_h(float val) { cout_h = val; }
        float Getcout_f() { return cout_f; }
        void Setcout_f(float val) { cout_f = val; }
        Point Getparent() { return parent; }
        void Setparent(Point val) { parent = val; }

    protected:

    private:
        float cout_g, cout_h, cout_f;
        Point parent;
};

#endif // NODE_H
