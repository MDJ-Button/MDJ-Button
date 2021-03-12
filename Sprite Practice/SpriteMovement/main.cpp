#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <fstream>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
    /*Pulls data from a editable ini file*/
     int w, h;
     string iwin; string ifull; string full;
     ifstream Settings("Config.ini");
     while (Settings >> iwin >> h >> w >> ifull >> full)
     {
         cout  << iwin << "=" << h << "x" << w << endl << ifull << "=" << full << endl;
     }
     Settings.close();

     /*Create window*/
     RenderWindow window;
     if (full == "Yes")
     {
        window.create (VideoMode(), "Untitled Project", Style::Fullscreen);
     }
     else
     {
        window.create (VideoMode(h, w), "Untitled Project");
     }

     FloatRect windowBounds(Vector2f(0.f , 0.f), window.getDefaultView().getSize());

     /*Loads textures*/

     /*Pumpy*/
     int KeepPumpyLeved = 245;
     Texture idle1;
     idle1.loadFromFile("Assests/Textures/idle (1).png");
     Sprite idle1s(idle1);
     idle1s.setScale(0.2, 0.2);
     idle1s.setPosition(0, w-KeepPumpyLeved);
     float idle1w = idle1s.getLocalBounds().width; float idle1h = idle1s.getLocalBounds().height;
        cout << "idle1=" << idle1w << "x" << idle1h << endl;
     float idle1x = idle1s.Transformable::getPosition().x; float idle1y = idle1s.Transformable::getPosition().y;
        cout << "idle1=" << idle1x << "x" << idle1y << endl;
        cout << "idle1=" << idle1x*w << "x" << idle1y*h << endl;

     /*Floor*/
     int KeepFloorLeved = 100;
     Texture floor;
     floor.loadFromFile("Assests/Textures/Ground.png");
     Sprite floorS(floor);
     floorS.setScale(1, 1);
     floorS.setPosition(0, w-KeepFloorLeved);
     int floorSw = floorS.getLocalBounds().width; int floorSh = floorS.getLocalBounds().height;
        cout << "floor=" << floorSw << "x" << floorSh << endl;
     int floorSx = floorS.Transformable::getPosition().x; int floorSy = floorS.Transformable::getPosition().y;
        cout << "floor=" << floorSx << "x" << floorSy << endl;
        cout << "floor=" << floorSx%w << "x" << floorSy%h << endl;

     /*Gravity Test*/
     const float maxY = 1;
     const Vector2f gravity(0.f,1.f);
     Vector2f velocity(0.f, 1.f);

     /*Window loop*/
     while (window.isOpen())
     {
         Event windowrender;
         while (window.pollEvent(windowrender))
         {
             if (windowrender.type == Event::Closed)
                window.close();
         }

         if (Keyboard::isKeyPressed(Keyboard::Right))
         {
            cout << "right";
            idle1s.move(5, 0);
         }

         if (Keyboard::isKeyPressed(Keyboard::Left))
         {
            cout << "left";
            idle1s.move(-5, 0);
         }

         if (Keyboard::isKeyPressed(Keyboard::Up))
         {
            cout << "up";
            idle1s.move(0, -10);
         }

         /*Dectection System*/
         FloatRect idle1sRect = idle1s.getGlobalBounds();
         FloatRect floorSRect = floorS.getGlobalBounds();
         if (idle1s.getPosition().x < floorS.getPosition().x + floorSRect.width &&
             idle1s.getPosition().x + idle1sRect.width > floorS.getPosition().x &&
             idle1s.getPosition().y < floorS.getPosition().y + floorSRect.height &&
             idle1sRect.height + idle1s.getPosition().y > floorS.getPosition().y)
         {
             cout << "Contact";
             idle1s.setPosition(0, w-KeepPumpyLeved);
         }

         //if (idle1y == 0)
         //{
             //idle1s.move(velocity);
             //if (velocity.y < maxY) velocity += gravity;
         //}

        window.clear();

        window.draw(floorS);
        window.draw(idle1s);

        window.setFramerateLimit(30);
        window.display();

     }



    return 0;
}
