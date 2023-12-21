#include "Complex.h"
#include <iostream>
using namespace std;

/***************************
 * COMPLEX
 * A complex number
 ***************************/

// Default constructor
Complex::Complex()
{
    real = 0.0;
    imaginary = 0.0;
}
// Non-default constructor
Complex::Complex(double r, double i)
{
    real = r;
    imaginary = i;
}
// Constructor to copy right-hand-side parameter
Complex::Complex(const Complex& complex)
{
    imaginary = complex.imaginary;
}

// Display a value
const void Complex::display()
{
    cout << real << " + "
        << imaginary << "i";
}

// Set a value
void Complex::set(double r, double i)
{
    real = r;
    imaginary = i;
}

// Two getters
const double Complex::getReal()
{
    return real;
}
const double Complex::getImaginary()
{
    return imaginary;
}