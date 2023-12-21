#include "testVelocity.h"

void TestVelocity::getDirectionUp_getDirection()
{
   // setup
   Velocity velocity;
   velocity.setDx(0.0);
   velocity.setDy(1.0);
   Direction direction;

   // exercise
   direction = velocity.getDirection();

   // verify
   assert(direction.getRadians() == 0);

   // teardown
}

void TestVelocity::getDirectionRight_getDirection()
{
   // setup
   Velocity velocity;
   velocity.setDx(1.0);
   velocity.setDy(0.0);
   Direction direction;

   // exercise
   direction = velocity.getDirection();

   // verify
   assert(direction.getRadians() == (M_PI / 2));

   // teardown
}

void TestVelocity::getDirectionUpRight_getDirection()
{
   // setup
   Velocity velocity;
   velocity.setDx(1.0);
   velocity.setDy(1.0);
   Direction direction;

   // exercise
   direction = velocity.getDirection();

   // verify
   assert(direction.getRadians() == M_PI / 4);

   // teardown
}

void TestVelocity::getDirectionLeft_getDirection()
{
   // setup
   Velocity velocity;
   velocity.setDx(-1.0);
   velocity.setDy(0.0);
   Direction direction;

   // exercise
   direction = velocity.getDirection();

   // verify
   assert(direction.getRadians() == -(M_PI / 2));

   // teardown
}

void TestVelocity::getDirectionDown_getDirection()
{
   // setup
   Velocity velocity;
   velocity.setDx(0.0);
   velocity.setDy(-1.0);
   Direction direction;

   // exercise
   direction = velocity.getDirection();

   // verify
   assert(direction.getRadians() == M_PI);

   // teardown
}

void TestVelocity::reverseUpRight_reverse()
{
   // setup
   Velocity velocity;
   velocity.setDx(1.0);
   velocity.setDy(1.0);

   // exercise
   velocity.reverse();

   // verify
   assert(velocity.getDx() == -1.0);
   assert(velocity.getDy() == -1.0);

   // teardown
}

void TestVelocity::reverseRight_reverse()
{
   // setup
   Velocity velocity;
   velocity.setDx(1.0);
   velocity.setDy(0.0);

   // exercise
   velocity.reverse();

   // verify
   assert(velocity.getDx() == -1.0);
   assert(velocity.getDy() == 0.0);

   // teardown
}
