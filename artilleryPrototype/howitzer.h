#pragma once
#include "position.h"
#include "direction.h"
#include "uiDraw.h"
#include "velocity.h"

#define PI 3.141592653589793238463

class Howitzer
{
private:
   Position position;
   double age;
   bool fired;
   Direction elevation;

public:
   Howitzer() 
   {
      fired = false;
      age = 0;
      elevation.setRadians(0);
   }

   Howitzer(Position pos, Direction dir, double time) 
   {
      fired = false;
      position = pos;
      if (-(PI / 2) <= dir.getRadians() <= (PI / 2))
         elevation = dir;
      else
         elevation.setRadians(0);
      age = time;
   }

   void setAge(double time) { age = time; };
   void SetFired(bool hasFired) { fired = hasFired; }
   bool isFired() { return fired; };
   void draw(ogstream& gout);
   void rotate(int input);
   void raise(int input);
   double getRadians() { return elevation.getRadians(); };
   void setPosition(Position pos) { position = pos; };
   Position getPosition() { return position; };   
};

