#pragma once
#include "position.h"
#include "uiDraw.h"
#include "velocity.h"

class testProjectile;

class Projectile
{
private:
   Position position;
   Velocity velocity;
   double gravity;
   double time;
   Direction radians;
   double mass;
   double dragCoef;
   double radius;
   double speedSound;
   double airDensity;
   double mach;
   double ddx;
   double ddy;
   double ddxTotal;
   double ddyTotal;
   bool flying;
   double areaOfShell;


   void areaOfCircle(double r);
   void gravityAltitude(double altitude);
   void calcDragCoef();
   void machAltitude(double altitude);
   void vertDistFormula(double y0, double t, double ddyTotal);
   void hrzDistFormula(double y0, double t, double ddxTotal);
   void hrzCompAccel(double a, double angle);
   void vertCompAccel(double a, double angle);
   double dragForce(double a);
   double newton2LawAccel(double m, double f);
   double reverseAngle();
   void hrzVelWConstA(double t);
   void vertVelWConstA(double t);
   void setLaunchPosition(int distance);

public:
   friend class testProjectile;
   Projectile() 
   {
      flying = false;
      gravity = -9.8;
      mass = 46.7;
      radius = 0.15489 / 2;
      areaOfCircle(radius);
      dragCoef = .3;
   }

   void fire(double time, double angle);
   void draw(ogstream& gout) { gout.drawProjectile(position, time); };
   void setMass(double m) { mass = m; }
   void setRadius(double r) { radius = r; }
   void setRadians(double r) { radians.setRadians(r); };

   bool getFlying() { return flying; };
   void setFlying(bool f) { flying = f; };
   double getAltitude() { return position.getMetersY(); };
   Position getPosition() { return position; };
   void setPosition(Position p);
   void setVelocity(double v) { velocity.setSpeed(v, radians.getRadians()); }

   // These should be public, but I couldn't get the "friend testProjectile" to
   // work. Thus, these will unfortinately have to remain public.
   double airDensityAltitude(double altitude);
   double linearInter(double d0, double r0, double d1,
      double r1, double d);
};
