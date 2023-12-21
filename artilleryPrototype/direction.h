#pragma once
class Direction
{
private:
   double radians;

public:
   Direction()
   {
      radians = 0;
   }

   void setRadians(double rhs) { radians = rhs; }
   double getRadians() { return radians; }
};

