#pragma once
#include "velocity.h"
#include <cassert>
#define _USE_MATH_DEFINES
#include <math.h>

class TestVelocity
{

public:
   void run()
   {
      getDirectionUp_getDirection();
      getDirectionRight_getDirection();
      getDirectionUpRight_getDirection();
      getDirectionLeft_getDirection();
      getDirectionDown_getDirection();
      reverseUpRight_reverse();
      reverseRight_reverse();
   }

private:
   void getDirectionUp_getDirection();
   void getDirectionRight_getDirection();
   void getDirectionUpRight_getDirection();
   void getDirectionLeft_getDirection();
   void getDirectionDown_getDirection();
   void reverseUpRight_reverse();
   void reverseRight_reverse();
};

