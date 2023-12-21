#include <iostream>
using namespace std;

/*******************************
 * THING
 * Store and display some thing
 *******************************/
template <class T>
class Thing
{
private:
    T _thing;

public:

    // non-default constructor
    Thing(const T &t) : _thing(t) {}

    // setter
    void set(const T &t)
    {
        this->_thing = t;
    }

    // getter
    T get() const
    {
        return &_thing;
    }

    // display
    void display() const
    {
        cout << _thing << endl;
    }
};