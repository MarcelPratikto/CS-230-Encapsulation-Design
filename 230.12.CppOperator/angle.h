/*************************************************************
 * 1. Name:
 *      Marcel Pratikto, Shirley Grant, Spencer Lameroux
 * 2. Module
 *      ANGLE
 * 3. Assignment Description:
 *      A class to represent an angle
 **************************************************************/

#pragma once

#define PI     3.141592653589793238462643383279502
#define TWO_PI 6.28318530718

#include <math.h>    // for floor()
#include <iostream>  // for cout
#include <cassert>   // for assert()
using namespace std;

class TestAngle;

/************************************
 * ANGLE
 ************************************/
class Angle
{
    friend TestAngle;

public:
    // Default constructor
    Angle() : radians(0.0) {}
    // Copy constructor
    Angle(const Angle& rhs) : radians(rhs.radians) {}
    // Non-default constructor
    Angle(double degrees) : radians(0.0)
    {
        setDegrees(degrees);
    }

    // Getters
    // set constant because it's not supposed to change the value it's getting
    double getDegrees() const
    {
        return convertToDegrees(radians);
    }
    double getRadians() const
    {
        return radians;
    }

    // Setters
    void setDegrees(double degrees)
    {
        radians = normalize(convertToRadians(degrees));
    }
    void setRadians(double radians)
    {
        this->radians = normalize(radians);
    }

    // Display
    void display(ostream& out) const
    {
        out.precision(1);
        out.setf(ios::fixed | ios::showpoint);
        out << getDegrees(); //<< "degrees";
    }

    /************************************
     * OPERATOR OVERLOAD DECLARATIONS
     ************************************/
    void operator= (Angle& angle);
    Angle& operator++ ();
    Angle& operator++ (int i);
    Angle& operator-- ();
    Angle& operator-- (int i);

private:
    // Convert functions
    double convertToDegrees(double radians) const
    {
        return normalize(radians) / TWO_PI * 360.0;
    }
    double convertToRadians(double degrees) const
    {
        return normalize(degrees / 360.0 * TWO_PI);
    }

    // Normalize
    double normalize(double radians) const
    {
        if (radians >= TWO_PI)
        {
            double multiples = floor(radians / TWO_PI);
            assert(radians - TWO_PI * multiples >= 0.0);
            assert(radians - TWO_PI * multiples <= TWO_PI);
            return radians - (TWO_PI * multiples);
        }
        else if (radians < 0.0)
        {
            double multiples = ceil(-radians / TWO_PI);
            assert(TWO_PI * multiples + radians >= 0.0);
            assert(TWO_PI * multiples + radians <= TWO_PI);
            return TWO_PI * multiples + radians;
        }

        assert(0.0 <= radians && radians <= TWO_PI);
        return radians;
    }

    double radians;
};

/************************************
 * OPERATOR OVERLOADS
 ************************************/
// Assignment
void Angle::operator= (Angle& angle)
{
    this->setDegrees(angle.getDegrees());
}

// Negation
// Negation
inline Angle& operator- (Angle& angle)
{
    Angle temp;
    temp.setRadians(angle.getRadians() + TWO_PI / 2);

    return temp;
}

// Equals
inline bool operator== (Angle& angle1, Angle& angle2)
{
    return (angle1.getDegrees() == angle2.getDegrees());
}

// Not Equals
inline bool operator!= (Angle& angle1, Angle& angle2)
{
    return (angle1.getDegrees() != angle2.getDegrees());
}

// Insertion
inline void operator<< (ostream& out, Angle& angle)
{
    angle.display(out);
}

// Extraction
inline void operator>> (istream& in, Angle& angle)
{
    double deg;
    in >> deg;
    if (!(in.fail()))
        angle.setDegrees(deg);
}

// Pre-Increment
Angle& Angle::operator++ ()
{
    double deg = this->getDegrees() + 1.0;
    this->setDegrees(deg);
    return *this;
}
// Post-Increment
Angle& Angle::operator++ (int i)
{
    double deg = this->getDegrees();
    this->setDegrees(deg + 1.0);
    Angle angle;
    angle.setDegrees(deg);
    return angle;
}

// Pre-Decrement
Angle& Angle::operator-- ()
{
    double deg = this->getDegrees() - 1.0;
    this->setDegrees(deg);
    return *this;
}
// Post-Decrement
Angle& Angle::operator-- (int i)
{
    double deg = this->getDegrees();
    this->setDegrees(deg - 1.0);
    Angle angle;
    angle.setDegrees(deg);
    return angle;
}