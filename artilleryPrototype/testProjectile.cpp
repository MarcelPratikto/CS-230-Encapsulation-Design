#include "testProjectile.h"

void TestProjectile::bothPointsSame_linearInter()
{
   // setup
   Projectile projectile;

   // exercise
   double linInter = projectile.linearInter(0.0, 0.0, 0.0, 0.0, 0.0);

   // verify
   assert(linInter == 0.00);

   // teardown
}

void TestProjectile::middleOnlyXChange_linearInter()
{
   // setup
   Projectile projectile;

   // exercise
   double linInter = projectile.linearInter(0.0, 0.0, 2.0, 0.0, 1.0);

   // verify
   assert(linInter == 0.00);

   // teardown
}

void TestProjectile::middleBothChange_linearInter()
{
   // setup
   Projectile projectile;

   // exercise
   double linInter = projectile.linearInter(0.0, 0.0, 2.0, 2.0, 1.0);

   // verify
   assert(linInter == 1.00);

   // teardown
}

void TestProjectile::forwardOneside_linearInter()
{
   // setup
   Projectile projectile;

   // exercise
   double linInter = projectile.linearInter(1.0, 2.0, 2.0, 3.0, 1.25);

   // verify
   assert(linInter == 2.25);

   // teardown
}

void TestProjectile::forwardOtherside_linearInter()
{
   // setup
   Projectile projectile;

   // exercise
   double linInter = projectile.linearInter(1.0, 2.0, 2.0, 3.0, 1.75);

   // verify
   assert(linInter == 2.75);

   // teardown
}

void TestProjectile::backwardOneSide_linearInter()
{
   // setup
   Projectile projectile;

   // exercise
   double linInter = projectile.linearInter(2.0, 2.0, 1.0, 3.0, 1.50);

   // verify
   assert(linInter == 2.50);

   // teardown
}

void TestProjectile::backwardOtherSide_linearInter()
{
   // setup
   Projectile projectile;

   // exercise
   double linInter = projectile.linearInter(2.0, 2.0, 1.0, 3.0, 1.75);

   // verify
   assert(linInter == 2.25);

   // teardown
}

// Air Density from Altitude function
void TestProjectile::seaLevel_airDensityAltitude()
{
   // setup
   Projectile projectile;
   double input = 0.0;

   // exercise
   double airDen = projectile.airDensityAltitude(input);

   // verify

   assert(closeEnough(airDen, 1.225, 0.001));

   // teardown
}

void TestProjectile::oneThousandFiveHundred_airDensityAltitude()
{
   // setup
   Projectile projectile;
   double input = 1500.0;

   // exercise
   double airDen = projectile.airDensityAltitude(input);

   // verify
   assert(closeEnough(airDen, 1.060, 0.001));

   // teardown
}

void TestProjectile::fourThousandOneHundred_airDensityAltitude()
{
   // setup
   Projectile projectile;
   double input = 4100.0;

   // exercise
   double airDen = projectile.airDensityAltitude(input);

   // verify
   assert(closeEnough(airDen, 0.8111, 0.001));

   // teardown
}

void TestProjectile::eightyThousand_airDensityAltitude()
{
   // setup
   Projectile projectile;
   double input = 80000.0;

   // exercise
   double airDen = projectile.airDensityAltitude(input);

   // verify
   assert(closeEnough(airDen, 0.0000185, 0.001));

   // teardown
}

bool TestProjectile::closeEnough(double value, double test, double tolerence) const
{
   double difference = value - test;
   return (difference >= -tolerence) && (difference <= tolerence);
}