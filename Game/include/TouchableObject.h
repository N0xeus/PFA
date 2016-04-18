#ifndef TOUCHABLEOBJECT_H
#define TOUCHABLEOBJECT_H


class TouchableObject
{
    public:
        TouchableObject();
        virtual ~TouchableObject();

        int Getid() { return id; }
        void Setid(int val) { id = val; }

    protected:
        int id;

    private:
};

#endif // TOUCHABLEOBJECT_H
