#include <iostream>
using namespace std;

///***************************
// * COMPLEX
// * A complex number
// ***************************/
//class Complex
//{
//public:
//    // Display a value
//    void display() const
//    {
//        cout << real << " + "
//            << imaginary << "i";
//    }
//
//    // Set a value
//    void set(double real, double imaginary)
//    {
//        this->real = real;
//        this->imaginary = imaginary;
//    }
//
//    // Two getters
//    double getReal() const
//    {
//        return real;
//    }
//    double getImaginary() const
//    {
//        return imaginary;
//    }
//
//private:
//    double real;
//    double imaginary;
//};
//
//// MAIN
//int main()
//{
//    /*int integer = 101;
//    double floatingPoint = 101.01;
//    bool boolean = true;
//    int* pInteger = &integer;
//    double* pFloatingPoint = &floatingPoint;
//    bool* pBoolean = &boolean;
//
//    cout << "pInteger: \t\t" << *pInteger << endl;
//    cout << "pFloatingPoint: \t" << *pFloatingPoint << endl;
//    cout << "pBoolean: \t\t" << *pBoolean << endl;
//
//    *pInteger = 99;
//    *pFloatingPoint = 99.99;
//    *pBoolean = false;
//
//    cout << "integer: \t\t" << integer << endl;
//    cout << "floatingPoint: \t\t" << floatingPoint << endl;
//    cout << "boolean: \t\t" << boolean << endl;*/
//
//    Complex* complex = new Complex();
//    complex->set(1.0, 2.0);
//    complex->display();
//}
//

/********************************************************************
 * FUNCTION
 * Demonstrate pass by value, pass by reference, and pass by pointer
 *******************************************************************/
void function(int value, int& reference, int* pointer)
{
    cout << "value:     " << value << " &value:     " << &value << endl;
    cout << "reference: " << reference << " &reference: " << &reference << endl;
    cout << "*pointer:  " << *pointer << " pointer:    " << pointer << endl;
}

/**********************************************************************
* Just call a function. No big deal really.
***********************************************************************/
int main()
{
    int number;
    cout << "Please give me a number: ";
    cin >> number;
    cout << "number:    " << number
        << "\t&number: " << &number
        << endl << endl;

    function(number  /*by value    */,
        number  /*by reference*/,
        &number /*by pointer  */);

    return 0;
}