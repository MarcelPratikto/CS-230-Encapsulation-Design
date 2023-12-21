/*************************************************************
 * 1. Name:
 *      Grant Shirley
 * 2. Assignment Name:
 *      Lab 08: M777 Howitzer
 * 3. Assignment Description:
 *      Firing the M777 howitzer 15mm artillery piece
 * 4. What was the hardest part? Be as specific as possible.
 *      The hardest part was getting the program to function
 *      at all. But, I got it working and though it's not perfect, 
 *      I'm pretty happy with it
 * 5. How long did it take for you to complete the assignment?
 *      8
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "position.h"   // for POSITION
#include "test.h"       // for Test
#include <iostream>     // for strings
#include <iomanip>
#include "howitzer.h"   // for HOWITZER
#include "projectile.h" // for PROJECTILE
using namespace std;

#define TIMERATE 0.5

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight),
      ground(ptUpperRight),
      time(0.0),
      angle(0.0),
      howitzer()
   {
      // Set the horizontal position of the howitzer. This should be random.
      ptHowitzer.setPixelsX(Position(ptUpperRight).getPixelsX() / 2.0);

      // Generate the ground and set the vertical position of the howitzer.
      ground.reset(ptHowitzer);
      howitzer.setPosition(ptHowitzer);
      // This is to make the bullet travel across the screen. Notice how there 
      // are 20 pixels, each with a different age. This gives the appearance
      // of a trail that fades off in the distance.
   }

   Howitzer howitzer;
   Projectile projectile;

   Ground ground;                 // the ground
   double bulletSpeed = 827;      // default projectile speed
   Position  ptHowitzer;          // location of the howitzer
   Position  ptUpperRight;        // size of the screen
   double angle;                  // angle of the howitzer 
   double time;                   // amount of time since the last firing
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo* pDemo = (Demo*)p;

   //
   // accept input
   //
   if (!pDemo->projectile.getFlying())
   {
      // move a large amount
      if (pUI->isRight())
         pDemo->howitzer.rotate(1);
      if (pUI->isLeft())
         pDemo->howitzer.rotate(-1);

   // move by a little
      if (pUI->isUp())
         pDemo->howitzer.raise(1);
      if (pUI->isDown())
         pDemo->howitzer.raise(-1);

   // fire that gun
      if (pUI->isSpace())
      {
         pDemo->time = 0.0;
         pDemo->projectile.setRadians(pDemo->howitzer.getRadians());
         pDemo->projectile.setPosition(pDemo->howitzer.getPosition());
         pDemo->projectile.setVelocity(pDemo->bulletSpeed);
         pDemo->projectile.setFlying(true);
      }
   }

   //
   // perform all the game logic
   //
   if (pDemo->projectile.getFlying())
   {
      pDemo->projectile.fire(TIMERATE, pDemo->angle);
      // advance time by half a second.
      pDemo->time += TIMERATE;
   }

   // If the projectile hits the ground, allow Howitzer to shoot another 
   // projectile
   if (pDemo->ground.getElevationMeters(pDemo->projectile.getPosition()) >=
      pDemo->projectile.getAltitude())
   {
      pDemo->projectile.setFlying(false);
   }

   // This is in charge of detecting when the projectile collides
   // with the target.
   if (pDemo->ground.getTarget().getMetersX() - 300 <= 
      pDemo->projectile.getPosition().getMetersX() && 
      pDemo->ground.getTarget().getMetersX() + 300 >=
      pDemo->projectile.getPosition().getMetersX() &&
      pDemo->ground.getTarget().getMetersY() - 300 <=
      pDemo->projectile.getPosition().getMetersY() &&
      pDemo->ground.getTarget().getMetersY() + 300 >=
      pDemo->projectile.getPosition().getMetersY())
   {
      Position pos;
      pDemo->ground.reset(pos);
      pDemo->howitzer.setPosition(pos);
      pDemo->projectile.setFlying(false);
   }

   //
   // draw everything
   //
   ogstream gout(Position(10.0, pDemo->ptUpperRight.getPixelsY() - 20.0));

   // draw the ground first
   pDemo->ground.draw(gout);

   // draw the howitzer
   pDemo->howitzer.setAge(pDemo->time);
   pDemo->howitzer.draw(gout);

   // draw the projectile
   if(pDemo->projectile.getFlying())
      pDemo->projectile.draw(gout);

   // draw some text on the screen
   gout.setf(ios::fixed | ios::showpoint);
   gout.precision(1);
   gout << "Time since the bullet was fired: "
        << pDemo->time << "s\n";
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setPixelsX(700.0);
   ptUpperRight.setPixelsY(500.0);
   Position().setZoom(40.0 /* 42 meters equals 1 pixel */);
   Interface ui(0, NULL,
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);

   testRunner();

   //runner();

   return 0;
}