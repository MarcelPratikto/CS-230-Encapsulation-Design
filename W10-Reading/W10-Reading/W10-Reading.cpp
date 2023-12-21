#include <iostream>
using namespace std;

int main()
{
    cout << "Start" << endl;
    try
    {
        throw "Error!";
        cout << "Middle" << endl;
    }
    catch (const char * message)
    {
        cout << "Caught" << endl;
    }
    
    cout << "End" << endl;
}