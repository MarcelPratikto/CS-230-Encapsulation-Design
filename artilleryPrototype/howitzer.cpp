#include "howitzer.h"

// This function calls the draw function for the Howitzer.
void Howitzer::draw(ogstream& gout)
{
   gout.drawHowitzer(position, elevation.getRadians(), age);
}

// This function is in charge of the left and right inputs and which
// direction to turn the Howitzer barrel.
void Howitzer::rotate(int input)
{
   double rad;

   if (input > 0)
      rad = 0.05;
   else
      rad = -0.05;

   rad += elevation.getRadians();

   if (-PI / 2 < rad && rad < PI / 2)
   {
      elevation.setRadians(rad);
   }
}

// This function is in charge of the up and down inputs and which
// direction to turn the Howitzer barrel. These inputs only turn the 
// Howitzer barrel a little to help with precise aiming.
void Howitzer::raise(int input)
{
   double rad;
   if (input > 0)
      rad = (elevation.getRadians() >= 0 ? -0.003 : 0.003);
   else
      rad = (elevation.getRadians() >= 0 ? 0.003 : -0.003);

   rad += elevation.getRadians();

   if (-PI / 2 < rad && rad < PI / 2)
   {
      elevation.setRadians(rad);
   }
}