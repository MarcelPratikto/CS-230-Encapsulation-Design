// W09-Reading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    /*int len = 5;
    double darray[] = { 0.0, 1.0, 2.0, 3.0, 4.0 };
    
    cout << "Using index loop: ";
    for (int i = 0; i < len; ++i)
    {
        cout << darray[i] << " ";
    }
    cout << endl;

    cout << "Using pointer loop: ";
    for (double* p = darray; p < darray + len; ++p)
    {
        cout << *p << " ";
    }
    cout << endl;*/

    const int len = 256;
    char text[len];
    cout << "What is your name? ";
    cin >> text;

    cout << "USING INDEX LOOP" << endl;
    for (int i = 0; i < len; ++i)
    {
        if (!text[i])
            i = 256;
        else
            cout << text[i] << endl;
    }

    cout << "USING POINTER LOOP" << endl;
    for (char* p = text; *p; ++p)
    {
        cout << *p << endl;
    }
}