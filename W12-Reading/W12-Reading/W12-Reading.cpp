#include <iostream>
using namespace std;

/********************
 * GPA
 ********************/
class GPA
{
private:
    float gpa;
public:
    // constructor
    GPA() : gpa(0.0) {};

    // getter
    float get() const
    {
        return gpa;
    }

    // setter
    void set(float rhs)
    {
        gpa = rhs;
    }

    // equals
    GPA& increment()
    {
        gpa += 0.1;
        return *this;
    }

    // prefix increment
    GPA& operator++()
    {
        gpa += 0.1;
        return *this;
    }

    // postfix increment
    GPA& operator++ (int num)
    {
        GPA gpaReturn;
        gpaReturn.set(this->gpa);
        this->gpa += 0.1;
        return gpaReturn;
    }
};


/********************
* MAIN
********************/
int main()
{
    GPA gpa;
    gpa.set(2.8);

    //gpa.increment();
    ++gpa;
    cout << gpa.get() << endl;

    gpa++;
    cout << gpa.get() << endl;

    return 0;
}