#include "projectile.h"

// This function sets the original position of the bullet when shot.
void Projectile::setPosition(Position p) 
{ 
   position = p; 
   setLaunchPosition(10);
}

// This function returns an updated position that allows you to put the 
// projectile however far away from the howitzer as needed.
// Currently it is used to help create the bullet at the end of the barrel
// rather than the base of it.
void Projectile::setLaunchPosition(int distance)
{
   double x = position.getPixelsX() + distance * sin(radians.getRadians());
   double y = position.getPixelsY() + distance * cos(radians.getRadians());
   position.setPixelsX(x);
   position.setPixelsY(y);
}

// This function performs the linear Interperlation equation.
double Projectile::linearInter(double d0, double r0, double d1, 
   double r1, double d) 
{
   double r = 0.0;
   if((d1 - d0) != 0)
      r = (((r1 - r0) * (d - d0)) / (d1 - d0)) + r0;

   return r;
}

// This function helps us find the air density at a specific altitude.
double Projectile::airDensityAltitude(double altitude)
{
   airDensity = 1.2250000;
   if (0 < altitude && altitude <= 1000)
      airDensity = linearInter(0, 1.2250000, 1000, 1.1120000, altitude);

   else if (1000 < altitude && altitude <= 2000)
      airDensity = linearInter(1000, 1.1120000, 2000, 1.0070000, altitude);

   else if (2000 < altitude && altitude <= 3000)
      airDensity = linearInter(2000, 1.0070000, 3000, 0.9093000, altitude);

   else if (3000 < altitude && altitude <= 4000)
      airDensity = linearInter(3000, 0.9093000, 4000, 0.8194000, altitude);

   else if (4000 < altitude && altitude <= 5000)
      airDensity = linearInter(4000, 0.8194000, 5000, 0.7364000, altitude);

   else if (5000 < altitude && altitude <= 6000)
      airDensity = linearInter(5000, 0.7364000, 6000, 0.6601000, altitude);

   else if (6000 < altitude && altitude <= 7000)
      airDensity = linearInter(6000, 0.6601000, 7000, 0.5900000, altitude);

   else if (7000 < altitude && altitude <= 8000)
      airDensity = linearInter(7000, 0.5900000, 8000, 0.5258000, altitude);

   else if (8000 < altitude && altitude <= 9000)
      airDensity = linearInter(8000, 0.5258000, 9000, 0.4671000, altitude);

   else if (9000 < altitude && altitude <= 10000)
      airDensity = linearInter(9000, 0.4671000, 10000, 0.4135000, altitude);

   else if (10000 < altitude && altitude <= 15000)
      airDensity = linearInter(10000, 0.4135000, 15000, 0.1948000, altitude);

   else if (15000 < altitude && altitude <= 20000)
      airDensity = linearInter(15000, 0.1948000, 20000, 0.0889100, altitude);

   else if (20000 < altitude && altitude <= 25000)
      airDensity = linearInter(20000, 0.0889100, 25000, 0.0400800, altitude);

   else if (25000 < altitude && altitude <= 30000)
      airDensity = linearInter(25000, 0.0400800, 30000, 0.0184100, altitude);

   else if (30000 < altitude && altitude <= 40000)
      airDensity = linearInter(30000, 0.0184100, 40000, 0.0039960, altitude);

   else if (40000 < altitude && altitude <= 50000)
      airDensity = linearInter(40000, 0.0039960, 50000, 0.0010270, altitude);

   else if (50000 < altitude && altitude <= 60000)
      airDensity = linearInter(50000, 0.0010270, 60000, 0.0003097, altitude);

   else if (60000 < altitude && altitude <= 70000)
      airDensity = linearInter(60000, 0.0003097, 70000, 0.0000828, altitude);

   else if (70000 < altitude && altitude <= 80000)
      airDensity = linearInter(70000, 0.0000828, 80000, 0.0000185, altitude);

   return airDensity;
}

// This function is responsible to moving the projectile after it was
// shot into the air.
void Projectile::fire(double time, double angle)
{
   airDensityAltitude(position.getMetersY());
   machAltitude(position.getMetersY());
   calcDragCoef();
   double dragF = dragForce(areaOfShell);
   double dragAccel = newton2LawAccel(mass, dragF);
   double oppositeRadians = reverseAngle();

   hrzCompAccel(dragAccel, oppositeRadians);
   gravityAltitude(position.getMetersY());
   vertCompAccel(dragAccel, oppositeRadians);

   vertVelWConstA(time);
   hrzVelWConstA(time);

   hrzDistFormula(position.getMetersX(), time, ddxTotal);
   vertDistFormula(position.getMetersY(), time, ddyTotal);

}

/*
*Velocity with Constant Acceleration
* v = velocity in meters (m/s)
* v0 = initial velocity (m/s)
* a = acceleration (m/s^2)
* timeFrame = time (s)
*/
void Projectile::hrzVelWConstA(double t)
{
   velocity.setDx(velocity.getDx() + ddxTotal * t);
}

/*
*Vertical Velocity with Constant Acceleration
* v = velocity in meters (m/s)
* v0 = initial velocity (m/s)
* a = acceleration (m/s^2)
* timeFrame = time (s)
*/
void Projectile::vertVelWConstA(double t)
{
   velocity.setDy(velocity.getDy() + ddyTotal * t);
}

/*
* Reverses the angle of the direction the object is moving
* so we can calculate the drag angle.
*/
double Projectile::reverseAngle()
{
   double pi = 2 * asin(1.0);
   double a = acos(velocity.getDy() / velocity.getSpeed());
   //cout << radiansToDegrees(a) << endl;
   a += pi;
   // cout << radiansToDegrees(a) << endl;
   return a;
}

// This performs Newtons 2 law to find acceleration.
double Projectile::newton2LawAccel(double m, double f)
{
   double a = f / m;
   return a;
}

// This function helps us find the drag force of the projectile.
double Projectile::dragForce(double a)
{
   double speed = velocity.getSpeed();
   double d = (dragCoef * airDensity * (speed * speed) * a) / 2;
   return d;
}

// This function helps us find the area of a circle.
void Projectile::areaOfCircle(double r)
{
   double pi = 2 * asin(1.0);
   double a = pi * (r * r);
   areaOfShell = a;
}

// This function helps us find the gravity and its force at specific altitudes.
void Projectile::gravityAltitude(double altitude)
{
   gravity = 0;
   if (0 < altitude && altitude <= 1000)
      gravity = linearInter(0, 9.807, 1000, 9.804, altitude);

   else if (1000 < altitude && altitude <= 2000)
      gravity = linearInter(1000, 9.804, 2000, 9.801, altitude);

   else if (2000 < altitude && altitude <= 3000)
      gravity = linearInter(2000, 9.801, 3000, 9.797, altitude);

   else if (3000 < altitude && altitude <= 4000)
      gravity = linearInter(3000, 9.797, 4000, 9.794, altitude);

   else if (4000 < altitude && altitude <= 5000)
      gravity = linearInter(4000, 9.794, 5000, 9.791, altitude);

   else if (5000 < altitude && altitude <= 6000)
      gravity = linearInter(5000, 9.791, 6000, 9.788, altitude);

   else if (6000 < altitude && altitude <= 7000)
      gravity = linearInter(6000, 9.788, 7000, 9.785, altitude);

   else if (7000 < altitude && altitude <= 8000)
      gravity = linearInter(7000, 9.785, 8000, 9.782, altitude);

   else if (8000 < altitude && altitude <= 9000)
      gravity = linearInter(8000, 9.782, 9000, 9.779, altitude);

   else if (9000 < altitude && altitude <= 10000)
      gravity = linearInter(9000, 9.779, 10000, 9.776, altitude);

   else if (10000 < altitude && altitude <= 15000)
      gravity = linearInter(10000, 9.776, 15000, 9.761, altitude);

   else if (15000 < altitude && altitude <= 20000)
      gravity = linearInter(15000, 9.761, 20000, 9.745, altitude);

   else if (20000 < altitude && altitude <= 25000)
      gravity = linearInter(20000, 9.745, 25000, 9.730, altitude);

   gravity *= -1;
}

// This helps us find the drag coefficient.
void Projectile::calcDragCoef()
{
   dragCoef = 0.3;

   if (0.300 < mach && mach < 0.500)
      dragCoef = linearInter(0.300, 0.1629, 0.500, 0.1659, mach);

   else if (0.500 < mach && mach < 0.700)
      dragCoef = linearInter(0.500, 0.1659, 0.700, 0.2031, mach);

   else if (0.700 < mach && mach < 0.890)
      dragCoef = linearInter(0.700, 0.2031, 0.890, 0.2597, mach);

   else if (0.890 < mach && mach < 0.920)
      dragCoef = linearInter(0.890, 0.2597, 0.920, 0.3010, mach);

   else if (0.920 < mach && mach < 0.960)
      dragCoef = linearInter(0.920, 0.3010, 0.960, 0.3287, mach);

   else if (0.960 < mach && mach < 0.980)
      dragCoef = linearInter(0.960, 0.3287, 0.980, 0.4002, mach);

   else if (0.980 < mach && mach < 1.000)
      dragCoef = linearInter(0.980, 0.4002, 1.000, 0.4258, mach);

   else if (1.000 < mach && mach < 1.020)
      dragCoef = linearInter(1.000, 0.4258, 1.020, 0.4335, mach);

   else if (1.020 < mach && mach < 1.060)
      dragCoef = linearInter(1.020, 0.4335, 1.060, 0.4483, mach);

   else if (1.060 < mach && mach < 1.240)
      dragCoef = linearInter(1.060, 0.4483, 1.240, 0.4064, mach);

   else if (1.240 < mach && mach < 1.530)
      dragCoef = linearInter(1.240, 0.4064, 1.530, 0.3663, mach);

   else if (1.530 < mach && mach < 1.990)
      dragCoef = linearInter(1.530, 0.3663, 1.990, 0.2897, mach);

   else if (1.990 < mach && mach < 2.870)
      dragCoef = linearInter(1.990, 0.2897, 2.870, 0.2297, mach);

   else if (2.870 < mach && mach < 2.890)
      dragCoef = linearInter(2.870, 0.2297, 2.890, 0.2306, mach);

   else if (2.890 < mach && mach < 5.000)
      dragCoef = linearInter(2.890, 0.2306, 5.000, 0.2656, mach);
}

// This helps us find the minimal speed to break the sound barrier at different
// altitudes.
void Projectile::machAltitude(double altitude)
{
   speedSound = 1;
   if (0 < altitude && altitude < 1000)
      speedSound = linearInter(0, 340, 1000, 336, altitude);

   else if (1000 < altitude && altitude < 2000)
      speedSound = linearInter(1000, 336, 2000, 332, altitude);

   else if (2000 < altitude && altitude < 3000)
      speedSound = linearInter(2000, 332, 3000, 328, altitude);

   else if (3000 < altitude && altitude < 4000)
      speedSound = linearInter(3000, 328, 4000, 324, altitude);

   else if (4000 < altitude && altitude < 5000)
      speedSound = linearInter(4000, 324, 5000, 320, altitude);

   else if (5000 < altitude && altitude < 6000)
      speedSound = linearInter(5000, 320, 6000, 316, altitude);

   else if (6000 < altitude && altitude < 7000)
      speedSound = linearInter(6000, 316, 7000, 312, altitude);

   else if (7000 < altitude && altitude < 8000)
      speedSound = linearInter(7000, 312, 8000, 308, altitude);

   else if (8000 < altitude && altitude < 9000)
      speedSound = linearInter(8000, 308, 9000, 303, altitude);

   else if (9000 < altitude && altitude < 10000)
      speedSound = linearInter(9000, 303, 10000, 299, altitude);

   else if (10000 < altitude && altitude < 15000)
      speedSound = linearInter(10000, 299, 15000, 295, altitude);

   else if (15000 < altitude && altitude < 20000)
      speedSound = linearInter(15000, 295, 20000, 295, altitude);

   else if (20000 < altitude && altitude < 25000)
      speedSound = linearInter(20000, 295, 25000, 295, altitude);

   else if (25000 < altitude && altitude < 30000)
      speedSound = linearInter(25000, 295, 30000, 305, altitude);

   else if (30000 < altitude && altitude < 40000)
      speedSound = linearInter(30000, 305, 40000, 324, altitude);

   mach = velocity.getSpeed() / speedSound;
}

/*
* Horizontal Distance Formula
* xt = horizontal position at time t (m)
* x0 = initial horizontal position (m)
* dx = horizontal component of velocity (m/s)
* ddx = horizontal component of acceleration (m/s^2)
* timeFrame = time (s)
*/
void Projectile::hrzDistFormula(double x0, double t, double ddxTotal)
{
   position.setMetersX(position.getMetersX() + (velocity.getDx() * t) + ((ddxTotal * (t * t)) / 2));
}

/*
* Vertical Distance Formula
* vt = vertical position at time t (m)
* v0 = initial vertical position (m)
* dv = vertical component of velocity (m/s)
* ddv = vertical component of acceleration (m/s^2)
* timeFrame = time (s)
*/
void Projectile::vertDistFormula(double y0, double t, double ddyTotal)
{
   position.setMetersY(position.getMetersY() + (velocity.getDy() * t) + ((ddyTotal * (t * t)) / 2));
}

/*
* Horizontal component of acceleration
* ddx = horizontal component of acceleration
* a = total acceleration
* angle = angle (0° is up) of the direction of acceleration
*/
void Projectile::hrzCompAccel(double a, double angle)
{
   ddx = a * sin(angle);
   ddxTotal = ddx;
}

/*
* Vertical component of acceleration
* ddy = vertical component of acceleration
* a = total acceleration
* angle = angle (0° is up) of the direction of acceleration
*/
void Projectile::vertCompAccel(double a, double angle)
{
   ddy = a * cos(angle);
   ddyTotal = ddy + gravity;
}