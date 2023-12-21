/*************************************************************
 * 1. Name:
 *      Marcel Pratikto
 * 2. Assignment Name:
 *      Lab 02: Apollo 11
 * 3. Assignment Description:
 *      Simulate the Apollo 11 landing
 * 4. What was the hardest part? Be as specific as possible.
 *      
 * 5. How long did it take for you to complete the assignment?
 *      
 *****************************************************************/

#define _USE_MATH_DEFINES // added before including cmath, needed to use M_PI
#include <iostream>  // for CIN and COUT
#include <cmath> // for COS, SIN, SQRT, RADIANS
using namespace std;


#define WEIGHT   15103.000   // Weight in KG
#define GRAVITY     -1.625   // Vertical acceleration due to gravity, in m/s^2
#define THRUST   45000.000   // Thrust of main engine, in Newtons (kg m/s^2)

/***************************************************
* COMPUTE DISTANCE
* Apply inertia to compute a new position using the distance equation.
* The equation is:
*     s = s + v t + 1/2 a t^2
* INPUT
*     s : original position, in meters
*     v : velocity, in meters/second
*     a : acceleration, in meters/second^2
*     t : time, in seconds
* OUTPUT
*     s : new position, in meters
**************************************************/
double computeDistance(double s, double v, double a, double t)
{
    s = s + v * t + a * (t * t) / 2.0;
    return s;
}

/**************************************************
* COMPUTE ACCELERATION
* Find the acceleration given a thrust and mass.
* This will be done using Newton's second law of motion:
*     f = m * a
* INPUT
*     f : force, in Newtons (kg * m / s^2)
*     m : mass, in kilograms
* OUTPUT
*     a : acceleration, in meters/second^2
***************************************************/
double computeAcceleration(double f, double m)
{
    double a = f / m;
    return a;
}

/***********************************************
* COMPUTE VELOCITY
* Starting with a given velocity, find the new
* velocity once acceleration is applied. This is
* called the Kinematics equation. The
* equation is:
*     v = v + a t
* INPUT
*     v : velocity, in meters/second
*     a : acceleration, in meters/second^2
*     t : time, in seconds
* OUTPUT
*     v : new velocity, in meters/second
***********************************************/
double computeVelocity(double v, double a, double t)
{
    v = v + a * t;
    return v;
}


/***********************************************
* COMPUTE VERTICAL COMPONENT
* Find the vertical component of a velocity or acceleration.
* The equation is:
*     cos(a) = y / total
* This can be expressed graphically:
*      x
*    +-----
*    |   /
*  y |  / total
*    |a/
*    |/
* INPUT
*     a : angle, in radians
*     total : total velocity or acceleration
* OUTPUT
*     y : the vertical component of the total
***********************************************/
double computeVerticalComponent(double a, double total)
{
    double y = cos(a) * total;
    return y;
}

/***********************************************
* COMPUTE HORIZONTAL COMPONENT
* Find the horizontal component of a velocity or acceleration.
* The equation is:
*     sin(a) = x / total
* This can be expressed graphically:
*      x
*    +-----
*    |   /
*  y |  / total
*    |a/
*    |/
* INPUT
*     a : angle, in radians
*     total : total velocity or acceleration
* OUTPUT
*     x : the vertical component of the total
***********************************************/
double computeHorizontalComponent(double a, double total)
{
    double x = sin(a) * total;
    return x;
}

/************************************************
* COMPUTE TOTAL COMPONENT
* Given the horizontal and vertical components of
* something (velocity or acceleration), determine
* the total component. To do this, use the Pythagorean Theorem:
*    x^2 + y^2 = t^2
* where:
*      x
*    +-----
*    |   /
*  y |  / total
*    | /
*    |/
* INPUT
*    x : horizontal component
*    y : vertical component
* OUTPUT
*    total : total component
***********************************************/
double computeTotalComponent(double x, double y)
{
    double total = sqrt(x * x + y * y);
    return total;
}


/*************************************************
* RADIANS FROM DEGEES
* Convert degrees to radians:
*     radians / 2pi = degrees / 360
* INPUT
*     d : degrees from 0 to 360
* OUTPUT
*     r : radians from 0 to 2pi
**************************************************/
double radiansFromDegrees(double d)
{
    double r = d * M_PI / 180;
    return r;
}

/**************************************************
* PROMPT
* A generic function to prompt the user for a double
* INPUT
*      message : the message to display to the user
* OUTPUT
*      response : the user's response
***************************************************/
double prompt(string prompt)
{
    cout << prompt;
    double output = 0.0;
    cin >> output;
    return output;
}

/****************************************************************
* MAIN
* Prompt for input, compute new position, and display output
****************************************************************/
int main()
{
    double aRadians = 0.0;            // Angle in radians
    double accelerationThrust = 0.0;  // Acceleration due to thrust 
    double ddxThrust = 0.0;           // Horizontal acceleration due to thrust
    double ddyThrust = 0.0;           // Vertical acceleration due to thrust
    double ddx = 0.0;                 // Total horizontal acceleration
    double ddy = 0.0;                 // Total vertical acceleration
    double v = 0.0;                   // Total velocity

    // Prompt for input and variables to be computed
    double dx = prompt("What is your horizontal velocity (m/s)? ");
    double dy = prompt("What is your vertical velocity (m/s)? ");
    double y = prompt("What is your altitude (m)? ");
    //double x = prompt("What is your position (m)? ");
    double x = 0.0;
    //double t = prompt("What is the time interval (s)? ");
    double t = 1.0;
    int time = 1;
    double aDegrees = 0.0;

    
    for (int numRotations = 0; numRotations < 2; ++numRotations)
    {
        if (numRotations == 0)
        {
            // initial angle of LM
            aDegrees = prompt("What is the angle of the LM where 0 is up (degrees)? ");
        }
        else
        {
            // allow for the pilot to rotate the RM after 5 secs of flight
            aDegrees = prompt("\nWhat is the new angle of the LM where 0 is up (degrees)? ");
        }

        // knowing the angle of the LM, calculate radians
        aRadians = radiansFromDegrees(aDegrees);

        // compute acceleration
        accelerationThrust = computeAcceleration(THRUST, WEIGHT);
        /*ddxThrust = computeAcceleration(accelerationThrust, WEIGHT);
        ddyThrust = computeAcceleration(accelerationThrust, WEIGHT);
        ddx = computeHorizontalComponent(aRadians, accelerationThrust);
        ddy = computeVerticalComponent(aRadians, accelerationThrust) + GRAVITY;*/
        ddxThrust = computeHorizontalComponent(aRadians, accelerationThrust);
        ddyThrust = computeVerticalComponent(aRadians, accelerationThrust);
        ddx = ddxThrust;
        ddy = ddyThrust + GRAVITY;

        // display 5 seconds of motion where the main engine is engaged
        cout << "\nFor the next 5 seconds with the main engine on, the position of the lander is:\n" << endl;
        for (int interval = 0; interval < 5; ++interval)
        {
            // compute new velocity
            dx = computeVelocity(dx, ddx, t);
            dy = computeVelocity(dy, ddy, t);
            v = computeTotalComponent(dx, dy);

            // compute new position
            x = computeDistance(x, dx, ddx, t);
            y = computeDistance(y, dy, ddy, t);

            cout.setf(ios::fixed | ios::showpoint);
            cout.precision(2);
            cout << time << "s - "
                << "x,y:(" << x << ", " << y << ")m "
                << "dx,dy:(" << dx << ", " << dy << ")m/s "
                << "speed:" << v << "m/s "
                << "angle:" << aDegrees << "deg"
                << endl;

            // add one second to time when done
            ++time;
        }
    }

    return 0;
}