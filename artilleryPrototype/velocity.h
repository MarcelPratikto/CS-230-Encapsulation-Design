#pragma once
#include "direction.h"
#include <cassert>

class Velocity
{
private:
   double dx;
   double dy;
   double speed;

public:
   Velocity() {}
   
   virtual void setDx(double xSpeed) { dx = xSpeed; }
   virtual void setDy(double ySpeed) { dy = ySpeed; }
   virtual void reverse();
   void setSpeed(double speed) { this->speed = speed; }
   void setSpeed(double speed, double a);
   void hrzCompVel(double a, double speed);
   void vertCompVel(double a, double speed);

   virtual double getDx() { return dx; }
   virtual double getDy() { return dy; }
   double getSpeed();
   virtual Direction getDirection();
};

