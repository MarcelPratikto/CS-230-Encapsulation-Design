// W04 Readings.cpp
#include <iostream>
#include "ArraysAndContainers.h"
#include "Complex.h"

int main()
{
    /*ArraysAndContainers AC;
    AC.li();*/

    Complex complex(1.0,2.0);
    Complex complex2(complex);
    
    complex.display();
    std::cout << "\n" << std::endl;
    complex2.display();
}
