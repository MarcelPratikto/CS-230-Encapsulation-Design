#include <iostream>
#include "Thing.h"
using namespace std;

template <class T>
void display(T inp)
{
    cout << "<<" << inp << ">>" << endl;
}

int main()
{
    /*display(7);
    display(3.1622);
    display("C++");*/

    Thing<int>* thing = new Thing<int>(7);
    thing->display();
    Thing<double>* thing2 = new Thing<double>(3.1622);
    thing2->display();
    Thing<string>* thing3 = new Thing<string>("C++");
    thing3->display();
}
