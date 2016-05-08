#ifndef POINT_H
#define POINT_H

class Point
{
    public:
        Point();
        Point(int, int);
        virtual ~Point();

        int Getx() const { return x; }
        void Setx(int val) { x = val; }
        int Gety() const { return y; }
        void Sety(int val) { y = val; }

    protected:

    private:
        int x;
        int y;
};



#endif // POINT_H
