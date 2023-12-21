#pragma once
#include "projectile.h"

class TestProjectile
{
public:
   void run()
   {
      // Linear interpolation function
      bothPointsSame_linearInter();
      middleOnlyXChange_linearInter();
      middleBothChange_linearInter();
      forwardOneside_linearInter();
      forwardOtherside_linearInter();
      backwardOneSide_linearInter();
      backwardOtherSide_linearInter();

      // Air Density from Altitude function
      seaLevel_airDensityAltitude();
      oneThousandFiveHundred_airDensityAltitude();
      fourThousandOneHundred_airDensityAltitude();
      eightyThousand_airDensityAltitude();
   }

private:
   void bothPointsSame_linearInter();
   void middleOnlyXChange_linearInter();
   void middleBothChange_linearInter();
   void forwardOneside_linearInter();
   void forwardOtherside_linearInter();
   void backwardOneSide_linearInter();
   void backwardOtherSide_linearInter();

   // Air Density from Altitude function
   void seaLevel_airDensityAltitude();
   void oneThousandFiveHundred_airDensityAltitude();
   void fourThousandOneHundred_airDensityAltitude();
   void eightyThousand_airDensityAltitude();

   bool closeEnough(double value, double test, double tolerence) const;
};

