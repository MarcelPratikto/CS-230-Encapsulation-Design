// W03 Reading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Complex
{
private:
    double real;
    double imaginary;

public:
    void display()
    {
        cout << real << " + " << imaginary << "i" << endl;
    }

    void set(double r, double i)
    {
        real = r;
        imaginary = i;
    }

    double getReal()
    {
        return real;
    }

    double getImaginary()
    {
        return imaginary;
    }
};

int main()
{
    Complex tObj;
    double r = tObj.getReal();
    tObj.display();
    tObj.set(34.1, -7);
    tObj.display();
}
