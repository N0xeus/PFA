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
#include "Obstacle.h"
#include "Enemy.h"
#include "Attack.h"
#include "HtH.h"
#include <time.h>

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
sf::Image icon;
list<Point> path;

Vector2f distance_vect(int, int, int, int);
float distance_f(int, int, int, int);
bool already_in_list(Point, node_list&);
void add_neighbour(Character&);
Point best_node(node_list&);
void add_closed_list(Point&);
void pathfinding();
void color_pixel(Point, Color);
void gravity();
void move_ch(Character&);

Vector2f speed = Vector2f(0.,0.);
Vector2f g = Vector2f(0.,1.);
float eps=1e-3;
bool b=true;

FloatRect r2 = FloatRect(-10000.,500.,50000.,5.);
FloatRect r3 = FloatRect(200,400,200,5);
FloatRect r4 = FloatRect(400,250,200,5);
RectangleShape rect;
RectangleShape rect2;
RectangleShape rect3(Vector2f(r3.width, r3.height));
RectangleShape rect4(Vector2f(r4.width, r4.height));

int main()
{
    RenderWindow app(VideoMode(800, 600), "Balles !");
    app.setFramerateLimit(60);
    icon.loadFromFile("img/icon.png");
    app.setIcon(100,100,icon.getPixelsPtr());
    Clock clock;

    Texture i;
    i.loadFromFile("img/bg1.jpg");
    RectangleShape bg = RectangleShape(Vector2f(1600,600));
    bg.setTexture(&i);
    View v;
    v.reset(FloatRect(0,0,800,600));

    carte.loadFromFile("img/bg1.jpg");

    Point current;
    sf::Clock timer;
    Int32 start_time;
    Attack* atq1 = new HtH(2,FloatRect(20,20,100,100),20,20);
    Enemy cube(1,FloatRect(100,450,50,50),Vector2f(10,0),100,*atq1,true,1,20,10);
    Obstacle obstacle(3, r2,10000);
    Enemy tmp;
    Vector2f dist;

    rect.setSize(Vector2f(cube.getHitbox().width,cube.getHitbox().height));
    rect.setPosition(cube.getHitbox().left, cube.getHitbox().top);
    rect2.setSize(Vector2f(obstacle.getHitbox().width,obstacle.getHitbox().height));
    rect2.setPosition(r2.left, r2.top);
    rect3.setPosition(r3.left, r3.top);
    rect4.setPosition(r4.left, r4.top);

    // Boucle principale
    while (app.isOpen())
    {
        Event event;

        while (app.pollEvent(event)){
            switch(event.type){
                case Event::Closed :
                    app.close();
                    break;
                default:
                    break;
            }
        }


        begin_point = cube.getPos();
        begin_node = Node(begin_point);
        end_point = Point(600,cube.getPosY());

        current = cube.getPos();
        tmp = Enemy(cube);

        open_list[current] = begin_node;
        add_closed_list(current);
        add_neighbour(cube);
        timer.restart();
        start_time = timer.getElapsedTime().asMilliseconds();

        while( (!(current == end_point) && !open_list.empty()) && (timer.getElapsedTime().asMilliseconds()-start_time < 10))
        {
            current = best_node(open_list);
            tmp.setPos(current);
            add_closed_list(current);
            add_neighbour(tmp);
        }

        if(current != end_point)
            end_point = current;

        pathfinding();
        // Remplissage de l'écran (couleur noire par défaut)
        app.clear();
        gravity();

        dist = distance_vect(cube.getPosX(),cube.getPosY(),end_point.Getx(),end_point.Gety());
        if(dist.x<speed.x)
        {
            speed.x = dist.x;
        }
        cout << dist.y << endl;
//        if(dist.y<speed.y){
//            speed.y = dist.y;
//        }

        move_ch(cube);
        speed.x = 0.;
        if(speed.y!=0) b=false;
        if(cube.getHitbox().intersects(r2)){
            speed.y=0;
            cube.setHitboxTop(r2.top-cube.getHitbox().height);
            b=true;
        }
        if(speed.y>0 && cube.getHitbox().intersects(r3)){
            speed.y=0;
            cube.setHitboxTop(r3.top-cube.getHitbox().height);
            b=true;
        }
        bool test;
        if(speed.y<=0) test=false;
        if(speed.y>0 && cube.getHitbox().top+cube.getHitbox().height<r4.top) test=true;
        if(test && cube.getHitbox().intersects(r4)){
            speed.y=0;
            cube.setHitboxTop(r4.top-cube.getHitbox().height);
            b=true;
        }
        rect.setPosition(cube.getHitbox().left, cube.getHitbox().top);

        app.draw(bg);
        app.draw(rect2);
        app.draw(rect3);
        app.draw(rect4);
        app.draw(rect);

        Vector2f pos = rect.getPosition();
        if(pos.x>v.getCenter().x) v.setCenter(rect.getPosition().x, v.getCenter().y);
        if(pos.x<v.getCenter().x-300) v.move(Vector2f(-10,0));
        app.setView(v);

        // Affichage de la fenêtre à l'écran
        app.display();
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//    for(node_list::iterator i = closed_list.begin(); i != closed_list.end(); i++)
//    {
//        color_pixel(i->first, Color::Red);
//    }
//    for(list<Point>::iterator i = path.begin(); i != path.end(); i++)
//    {
//        color_pixel(*i, Color::Green);
//    }
//    color_pixel(begin_point, Color::Yellow);
//    color_pixel(end_point, Color::Blue);

    return EXIT_SUCCESS;
}

Vector2f distance_vect(int x1, int y1, int x2, int y2)
{
    return Vector2f(sqrt((x1-x2)*(x1-x2)),sqrt((y1-y2)*(y1-y2)));
}

float distance_f(int x1, int y1, int x2, int y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

bool already_in_list(Point p, node_list& nl)
{
    node_list::iterator i = nl.find(p);
    if(i==nl.end()) return false;
    else return true;
}

void add_neighbour(Character& p)
{
    Node tmp;
    bool no_obstacle = true;
    bool good = true;
    Point a;

    for(int i=p.getHitbox().left-1; i<=p.getHitbox().left+p.getHitbox().width+1; i++)
    {
        // En dehors de l'image, on passe au suivant
        if((i<0) ||  (i>=(int)carte.getSize().x)){
            good = false;
            continue;
        }

        for(int j=p.getHitbox().top; j<=p.getHitbox().top+p.getHitbox().height; j++)
        {
            // En dehors de l'image, on passe au suivant
            if((j<0) ||  (j>=(int)carte.getSize().y)){
                good = false;
                continue;
            }

            // Case actuelle, on passe au suivant
            if(p.getHitbox().contains(i,j)){
                good = false;
                continue;
            }

            // Obstacle, on passe au suivant
            if(/*there is an obstacle*/){
                cout << "obstacle" << endl;
                no_obstacle = false;
                continue;
            }


            if(i<p.getHitbox().left){
                a = Point(p.getPosX()-1,p.getPosY());
            } else if(i>p.getHitbox().left+p.getHitbox().width){
                a = Point(p.getPosX()+1,p.getPosY());
            } else {
                a = begin_point;
            }
        }

        if(!already_in_list(a, closed_list))
        {
            tmp.Setcout_g(closed_list[p.getPos()].Getcout_g() + distance_f(a.Getx(), a.Gety(), p.getPosX(), p.getPosY()));
            tmp.Setcout_h(distance_f(a.Getx(), a.Gety(), end_point.Getx(), end_point.Gety()));
            tmp.Setcout_f(tmp.Getcout_g() + tmp.Getcout_h());
            tmp.Setparent(p.getPos());

            if(already_in_list(a, open_list))
            {
                if(tmp.Getcout_f() < open_list[a].Getcout_f()){
                    open_list[a] = tmp;
                }
            } else {
                open_list[a] = tmp;
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
    speed.x = (n.Getx() - begin_point.Getx())*10;
}

void move_ch(Character& c){
    c.setHitboxLeft(c.getHitbox().left+speed.x);
    c.setHitboxTop(c.getHitbox().top+speed.y);
    c.setPos(Point(c.getPosX()+speed.x,c.getPosY()+speed.y));
}

void gravity(){
    speed+=g;
}
