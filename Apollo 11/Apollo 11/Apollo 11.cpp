/*************************************************************
 * 1. Name:
 *      Marcel Pratikto, Grant Shirley, Spencer Lamoreaux
 * 2. Assignment Name:
 *      Lab 05: Apollo 11 Code Complete
 * 3. Assignment Description:
 *      Simulate the Apollo 11 landing
 * 4. What was the hardest part? Be as specific as possible.
 *      Setting up all the classes, debugging
 * 5. How long did it take for you to complete the assignment?
 *      4 hours
 *****************************************************************/

 /**********************************************************************
  * GL Demo
  * Just a simple program to demonstrate how to create an Open GL window,
  * draw something on the window, and accept simple user input
  **********************************************************************/

#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ground.h"
#include "LunarModule.h"
#include "physics.h"
#include <list>
using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
    Demo(const Point& ptUpperRight) :
        angle(0.0),
        ptStar(ptUpperRight.getX() - 20.0, ptUpperRight.getY() - 20.0),
        ptLM(ptUpperRight.getX() / 2.0, ptUpperRight.getY() / 2.0),
        ground(ptUpperRight)
    {
        //phase = random(0, 255);
        for (int i = 0; i < 50; i++)
        {
            starsList.push_back(Point(random(0, 400), random(0, 400)));
        }
    }

    // this is just for test purposes.  Don't make member variables public!
    Point ptLM;           // location of the LM on the screen
    Point ptUpperRight;   // size of the screen
    double angle;         // angle the LM is pointing
    //unsigned char phase;  // phase of the star's blinking
    Ground ground;
    Point ptStar;
    list<Point> starsList;
};

// Lunar Module Object
LunarModule* LM;
/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
    ogstream gout;

    // the first step is to cast the void pointer into a game object. This
    // is the first step of every single callback function in OpenGL. 
    Demo* pDemo = (Demo*)p;
    
    double x = pDemo->ptLM.getX();
    double y = pDemo->ptLM.getY();
    Point *prevPoint = new Point(x, y);

    bool isThrustersOn = false;
    // move the ship around
    if (pUI->isRight())
        pDemo->ptLM.addX(1.0);
    if (pUI->isLeft())
        pDemo->ptLM.addX(-1.0);
    if (pUI->isUp())
        isThrustersOn = true;
        if (pUI->isRight())
            pDemo->angle -= 0.1;
        else if (pUI->isLeft())
            pDemo->angle += 0.1;
        else
            pDemo->ptLM.addY(1.0);
    if (pUI->isDown())
        if (pUI->isRight())
            pDemo->angle += 0.1; //pDemo->angle -= 0.1;
        else if (pUI->isLeft())
            pDemo->angle -= 0.1; //pDemo->angle += 0.1;
        else
            pDemo->ptLM.addY(-1.0);

    // draw our little stars
    for (Point star : pDemo->starsList)
    {
        gout.drawStar(star, random(0, 255));
    }

    // draw the ground
    pDemo->ground.draw(gout);

    // update lander
    Physics* physics = new Physics();
    x = pDemo->ptLM.getX();
    y = pDemo->ptLM.getY();
    Point *currPoint = new Point(x, y);
    double xdist = currPoint->getX() - prevPoint->getX();
    double ydist = currPoint->getY() - prevPoint->getY();
    double totalDistTraveled = physics->computeTotalComponent(xdist, ydist);
    double aDegrees = pDemo->angle;
    bool isTurning = false;
    if (aDegrees != 0.0) {
        isTurning = true;
    }
    const double aRadians = physics->radians(aDegrees);
    double dx = physics->computeHoriztalComponent(aRadians, totalDistTraveled);
    double dy = physics->computeVerticalComponent(aRadians, totalDistTraveled);
    LM->updatePosition(x, y);
    LM->updateVelocity(dx, dy);
    LM->updateAngle(aDegrees);
    LM->updateFuel(isTurning, isThrustersOn);

    // draw the lander and its flames
    gout.drawLander(pDemo->ptLM /*position*/, pDemo->angle /*angle*/);
    gout.drawLanderFlames(pDemo->ptLM, pDemo->angle, /*angle*/
        pUI->isDown(), pUI->isLeft(), pUI->isRight());

    // put some text on the screen
    gout.setPosition(Point(10.0, 380.0));
    //gout << "Demo (" << (int)pDemo->ptLM.getX() << ", " << (int)pDemo->ptLM.getY() << ")" << "\n";
    gout << "Fuel:\t\t" << LM->getFuel() << "\n";
    gout << "Altitude:\t\t" << (int)pDemo->ptLM.getY() << "\n";
    gout << "Velocity:\t\t" << LM->getVelocity() << "\n";
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
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
    Point ptUpperRight(400.0, 400.0);
    Interface ui(0, NULL,
        "Open GL Demo",
        ptUpperRight);

    // Initialize the game class
    Demo demo(ptUpperRight);

    // Lunar Module Object
    LM = new LunarModule();

    // set everything into action
    ui.run(callBack, &demo);

    return 0;
}
