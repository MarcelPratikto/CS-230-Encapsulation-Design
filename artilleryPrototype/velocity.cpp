#include "velocity.h"
#include <math.h>

// This helps us get the direction/angle in radians depending on the 
// velocity of the object.
Direction Velocity::getDirection() 
{ 
   Direction dir;
   dir.setRadians(atan2(dx, dy));
   return dir;
}

// This function allows us to find the reverse speed.
void Velocity::reverse()
{
   dx = dx * -1;
   dy = dy * -1;
}

// this function allows us to set the speed while only requiring a
// speed and angle.
void Velocity::setSpeed(double speed, double a)
{
   hrzCompVel(a, speed);
   vertCompVel(a, speed);
}

/*
* Horizontal component of speed
* dx = horizontal component of velocity
* s = overall speed (m/s)
* a = angle, direction of travel where 0 is pointing up (radians)
*/
void Velocity::hrzCompVel(double a, double speed)
{
   dx = speed * sin(a);
}

/*
* Vertical component of speed
* dy = vertical component of velocity
* s = overall speed (m/s)
* a = angle, direction of travel where 0 is pointing up (radians)
*/
void Velocity::vertCompVel(double a, double speed)
{
   dy = speed * cos(a);
}

// This function performs Pythageron therom to find the total speed.
double Velocity::getSpeed()
{
   return sqrt((dx * dx) + (dy * dy));
}