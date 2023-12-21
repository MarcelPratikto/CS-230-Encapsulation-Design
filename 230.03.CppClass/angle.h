/*************************************************************
 * 1. Name:
 *      Marcel Pratikto
 * 2. Assignment Name:
 *      Practice 03: Angle Class
 * 3. Assignment Description:
 *      A class to represent an angle
 * 4. What was the hardest part? Be as specific as possible.
 *      Trying to setup the already existing project using VS Code
 *		Figuring out the normalize() method
 * 5. How long did it take for you to complete the assignment?
 *      3 hours
 **************************************************************/

#pragma once

#define TWO_PI 6.28318530718
#define PI 3.14159265358

#include <math.h>    // for floor()
#include <iostream>  // for cout
#include <cassert>   // for assert()
using namespace std;

class TestAngle;

 /************************************
  * ANGLE
  *	class that represents an angle
  * 
  * methods
  ************************************/
class Angle
{
   friend TestAngle;	// for unit test

private:
   double radians = 0.0;

   double normalize(double rad)
   {
	   while ((rad < 0.0) || (rad > TWO_PI))
	   {
		   if (rad < 0.0)
		   {
			   rad += TWO_PI;
		   }
		   if (rad > TWO_PI)
		   {
			   rad -= TWO_PI;
		   }
	   }
	   
	   return rad;
   }

   double convertToDegrees(double rad)
   {
	   rad = normalize(rad);
	   double deg = rad * 180.0 / PI;
	   return deg;
   }

   double convertToRadians(double deg)
   {
	   double rad = deg * PI / 180.0;
	   rad = normalize(rad);
	   return rad;
   }

public:
	// return the angle in degrees
   double getDegrees()
   {
	   return convertToDegrees(radians);
   }

   // return the angle in radians
   double getRadians()
   {
	   return radians;
   }

   // set the angle using a degree
   void setDegrees(double deg)
   {
		// make sure that degree "unwraps"
		// value stays between 0 and 360
	   double rad = convertToRadians(deg);
	   rad = normalize(rad);
	   deg = convertToDegrees(rad);

	   radians = convertToRadians(deg);
   }

   // set the angle using a radian
   void setRadians(double rad)
   {
	   rad = normalize(rad);
	   radians = rad;
   }

   // 
   void display(ostream& out)
   {
	   out.setf(ios::fixed);     // "fixed" means don't use scientific notation
	   out.setf(ios::showpoint); // "showpoint" means always show the decimal point
	   out.precision(1);         // Set the precision to 1 decimal place of accuracy.
	   out << convertToDegrees(radians) << "degrees";
	   
	   //cout.setf(ios::fixed);     // "fixed" means don't use scientific notation
	   //cout.setf(ios::showpoint); // "showpoint" means always show the decimal point
	   //cout.precision(1);         // Set the precision to 1 decimal place of accuracy.
	   //cout << convertToDegrees(radians) << "degrees" << endl;
   }
};


