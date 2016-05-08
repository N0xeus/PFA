#include "Node.h"

Node::Node()
{
    cout_g = cout_f = cout_h = 0;
    parent = Point();
}

Node::Node(Point p)
{
    cout_g = cout_f = cout_h = 0;
    parent = p;
}

Node::~Node()
{
    //dtor
}
