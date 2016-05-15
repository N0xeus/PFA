#include <iostream>
#include <cmath>
#include <map>
#include <list>
#include <utility>
#include <string>
#include <sstream>
#include "Node.h"
#include "Point.h"
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "TouchableObject.h"

using namespace std;
using namespace sf;


bool operator==(Point const &a, Point const &b)
{
    if((a.Getx()==b.Getx()) && (a.Gety()==b.Gety()))
        return true;
    return false;
}

bool operator!=(Point const &a, Point const &b)
{
    if((a.Getx()==b.Getx()) && (a.Gety()==b.Gety()))
        return false;
    return true;
}

bool operator<(Point const &a, Point const &b)
{
    if(a.Getx()<b.Getx())
        return true;
    else if((a.Getx()==b.Getx()) && (a.Gety()<b.Gety()))
        return true;
    return false;
}

bool operator<=(Point const &a, Point const &b)
{
    if(a.Getx()<b.Getx())
        return true;
    else if((a.Getx()==b.Getx()) && (a.Gety()<=b.Gety()))
        return true;
    return false;
}

bool operator>(Point const &a, Point const &b)
{
    if(a.Getx()>b.Getx())
        return true;
    else if((a.Getx()==b.Getx()) && (a.Gety()>b.Gety()))
        return true;
    return false;
}
bool operator>=(Point const &a, Point const &b)
{
    if(a.Getx()>b.Getx())
        return true;
    else if((a.Getx()==b.Getx()) && (a.Gety()>=b.Gety()))
        return true;
    return false;
}

struct compare_points {
    bool operator()(const Point& a, const Point& b) const {
        return a < b;
    }
};

typedef map<Point, Node, compare_points> node_list;
node_list open_list;
node_list closed_list;
Node begin_node;
Point end_point;
Point begin_point;
sf::Image carte;
sf::Image result;
list<Point> path;

const Vector2f g = Vector2f(0.,10);
Vector2f speed = Vector2f(0.,0.);
const float eps = 1e-3;

float distance(int, int, int, int);
bool already_in_list(Point, node_list&);
void add_neighbour(Point&);
Point best_node(node_list&);
void add_closed_list(Point&);
void pathfinding();
void color_pixel(Point, Color);
void ground(Shape&);
void gravity(Shape&);
void move1(Shape&);

int main()
{
    RenderWindow window(VideoMode(800, 600), "Balles !");
    window.setFramerateLimit(60);

    carte.loadFromFile("img/blank.png");
    window.setIcon(14,10,carte.getPixelsPtr());
    result.loadFromFile("img/blank.png");
    window.setIcon(14,10,result.getPixelsPtr());
    begin_point = Point(0,0);
    begin_node = Node(begin_point);
    end_point = Point(carte.getSize().x-2, carte.getSize().y-1);

    Point current(0,0);

    open_list[current] = begin_node;
    add_closed_list(current);
    add_neighbour(current);

    while( !(current == end_point) && !open_list.empty())
    {
        current = best_node(open_list);
        add_closed_list(current);
        add_neighbour(current);
    }

    if(current == end_point) pathfinding();

    for(node_list::iterator i = closed_list.begin(); i != closed_list.end(); i++)
    {
        color_pixel(i->first, Color::Red);
    }
    for(list<Point>::iterator i = path.begin(); i != path.end(); i++)
    {
        color_pixel(*i, Color::Green);
    }
    color_pixel(begin_point, Color::Yellow);
    color_pixel(end_point, Color::Blue);

    result.saveToFile("result.png");

    return EXIT_SUCCESS;
}

float distance(int x1, int y1, int x2, int y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

bool already_in_list(Point p, node_list& nl)
{
    node_list::iterator i = nl.find(p);
    if(i==nl.end()) return false;
    else return true;
}

void add_neighbour(Point& p)
{
    Node tmp;

    for(int i=p.Getx()-1; i<=p.Getx()+1; i++)
    {
        // En dehors de l'image, on passe au suivant
        if((i<0) ||  (i>=(int)carte.getSize().x))
            continue;

        for(int j=p.Gety()-1; j<=p.Gety()+1; j++)
        {
            // En dehors de l'image, on passe au suivant
            if((j<0) ||  (j>=(int)carte.getSize().y))
                continue;

            // Case actuelle, on passe au suivant
            if((i==p.Getx()) && (j==p.Gety()))
                continue;

            // Obstacle, on passe au suivant
            if(carte.getPixel(i,j) == Color::Black)
                continue;

            Point a = Point(i,j);

            if(!already_in_list(a, closed_list))
            {
                tmp.Setcout_g(closed_list[p].Getcout_g() + distance(a.Getx(), a.Gety(), p.Getx(), p.Gety()));

                tmp.Setcout_h(distance(a.Getx(), a.Gety(), end_point.Getx(), end_point.Gety()));
                tmp.Setcout_f(tmp.Getcout_g() + tmp.Getcout_h());
                tmp.Setparent(Point(Point(p.Getx(),p.Gety())));

                if(already_in_list(a, open_list))
                {
                   if(tmp.Getcout_f() < open_list[a].Getcout_f())
                        open_list[a] = tmp;
                } else {
                    open_list[a] = tmp;
                }
            }
        }
    }
}

Point best_node(node_list& nl)
{
    float coutf = nl.begin()->second.Getcout_f();
    Point p = nl.begin()->first;

    for(node_list::iterator i = nl.begin(); i != nl.end(); i++)
    {
        if(i->second.Getcout_f() < coutf)
        {
            coutf = i->second.Getcout_f();
            p = i->first;
        }
    }

    return p;
}

void add_closed_list(Point& p)
{
    Node& n = open_list[p];
    closed_list[p] = n;

    if(open_list.erase(p) == 0) cerr << "Erreur, ce noeud n'est pas dans la liste ouverte" << endl;
    return;
}

void pathfinding()
{
    Node& tmp = closed_list[Point(end_point.Getx(),end_point.Gety())];

    Point n;
    n.Setx(end_point.Getx());
    n.Sety(end_point.Gety());
    path.push_front(n);

    while(tmp.Getparent() != begin_point)
    {
        n.Setx(tmp.Getparent().Getx());
        n.Sety(tmp.Getparent().Gety());
        path.push_front(n);

        tmp = closed_list[tmp.Getparent()];
    }

    path.push_front(Point(tmp.Getparent().Getx(),tmp.Getparent().Gety()));
}

void color_pixel(Point p, Color c)
{
    if(result.getPixel(p.Getx(),p.Gety()) != Color::Black) result.setPixel(p.Getx(), p.Gety(), c);
}

void ground(Shape& shape)
{
    Vector2f pos = shape.getPosition();

    if(pos.y>500.){
        shape.setPosition(pos.x, 500.);
        if(abs(speed.y)<eps){
            speed.y=0;
        }else speed.y*=-0.5;
    }
    if(abs(speed.x)<eps){
        speed.x=0;
    }else speed.x*=0.5;
}

void gravity(Shape& shape)
{
    speed+=g;
    ground(shape);
}

void move1(Shape& shape)
{
    shape.setPosition(shape.getPosition()+speed);
}
/*
int main()
{
    RenderWindow app(VideoMode(800, 600), "Balles !");
    app.setFramerateLimit(60);

    CircleShape circle1(50,4);
    circle1.setPosition(50, 0);
    circle1.setFillColor(Color(255, 0, 0));

    CircleShape circle2(50);
    circle1.setPosition(50, 0);
    circle1.setFillColor(Color(255, 0, 0));

//    RectangleShape rect(Vector2f(400,25));
//    rect.setOrigin(200,12.5);
//    rect.setPosition(400,300);
//    rect.setFillColor(Color::Black);
//    rect.setOutlineColor(Color::White);
//    rect.setOutlineThickness(5.);
//    int i=1;
//    RectangleShape rect2(Vector2f(40,25));
//    rect2.setOrigin(200,12.5);
//    rect2.setPosition(400,300);
//    rect2.setFillColor(Color::White);
//    rect2.setSize(Vector2f(40*i,25));

    Clock clock;

    // Boucle principale
    while (app.isOpen())
    {
        Event event;

        while (app.pollEvent(event)){
            switch(event.type){
                case Event::Closed : app.close(); break;

                case Event::KeyPressed : {
                    switch(event.key.code){
                        case Keyboard::Up :
                        case Keyboard::Z : {
                            speed.y=1000;
                        }break;

                        case Keyboard::Down :
                        case Keyboard::S : {

                        }break;

                        case Keyboard::Left :
                        case Keyboard::Q : {
                            speed.x=-1000;
                        }break;

                        case Keyboard::Right :
                        case Keyboard::D : {
                            speed.x=1000;
                        }break;
                    }
                }break;

                case Event::KeyReleased :{
                    switch(event.key.code){
                        case Keyboard::Left :
                        case Keyboard::Right :
                        case Keyboard::Q :
                        case Keyboard::D : {

                        }break;
                    }
                }break;
            }
        }

        // Remplissage de l'écran (couleur noire par défaut)
        app.clear();
        circle1.setPosition(circle1.getPosition()+speed*clock.restart().asSeconds());
        gravity(circle1);
        app.draw(circle1);
//        app.draw(rect);
//        app.draw(rect2);

        // Affichage de la fenêtre à l'écran
        app.display();
    }
    return EXIT_SUCCESS;
}
*/
