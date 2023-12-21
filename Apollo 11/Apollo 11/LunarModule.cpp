#include "LunarModule.h"
#include "physics.h"

LunarModule::LunarModule() {
	accelerationThrust = 0.0;
	ddxThrust = 0.0;
	ddyThrust = 0.0;
	ddx = 0.0;
	ddy = 0.0;
	angle = 0.0;
	verticalVelocity = 0.0;
	horizontalVelocity = 0.0;
	thrusters = 0.0;
	inertia = 0.0;
	fuel = 5000.0;
	location = 0.0;
	weight = 0.0;
	totalVelocity = 0.0;
	acceleration = 0.0;
	point = new Point(0.0, 0.0);
}

void LunarModule::updatePosition(double x, double y) {
	return;
}

void LunarModule::updateVelocity(double dx, double dy) {
	Physics* p = new Physics();
	totalVelocity = p->computeTotalComponent(dx, dy);
}

void LunarModule::updateAngle(double aDegrees) {
	angle = aDegrees;
}

void LunarModule::updateFuel(bool isTurning, bool isThrustersOn) {
	if (fuel > 0) {
		if (isTurning) {
			fuel -= 1;
		}
		if (isThrustersOn) {
			fuel -= 10;
		}
	}
}

double LunarModule::getFuel() {
	return fuel;
}

double LunarModule::getVelocity() {
	return totalVelocity;
}