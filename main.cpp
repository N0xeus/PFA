//#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;

CircleShape shape(50);
float vx=0;
float vy=0;

void mv(){
    float X=shape.getPosition().x;
    float Y=shape.getPosition().y;
    shape.setPosition(X+vx, Y+vy);
}

int main()
{
    RenderWindow app(VideoMode(800, 600), "Ma premiere fenetre SFML ! ");

    shape.setPosition(350, 250);

    // set the shape color to green
    shape.setFillColor(Color(255, 0, 0));

    // Boucle principale
    while (app.isOpen())
    {
        Event event;

        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed) app.close();
            if(event.type==event.KeyPressed){
                printf("(%f, %f)\n", shape.getPosition().x, shape.getPosition().y);
                if(event.key.code==Keyboard::D){
                    if(Keyboard::isKeyPressed(Keyboard::Q)) vx=0;
                    if(vx<0.1) vx=vx+0.1;
                }
                if(event.key.code==Keyboard::Q){
                    if(Keyboard::isKeyPressed(Keyboard::D)) vx=0;
                    if(vx>-0.1) vx=vx-0.1;
                }
                if(event.key.code==Keyboard::Z){
                    if(vy>-0.1) vy=vy-0.1;
                }
            }
            if(event.type==event.KeyReleased){
                if(event.key.code==Keyboard::D || event.key.code==Keyboard::Q) vx=0;
                if(event.key.code==Keyboard::Z) vy=0;
            }
        }

        // Remplissage de l'écran (couleur noire par défaut)
        app.clear();
        mv();
        app.draw(shape);

        // Affichage de la fenêtre à l'écran
        app.display();
    }
    return EXIT_SUCCESS;
}
