#include <iostream>
#include <cassert>
#include <string>
using namespace std;

double computePay(double hours, double wage)
{
    if (hours < 40.0)
        return hours * wage;
    else
        return (wage * 40.0) + (wage * 1.5 * (hours - 40.0));
}


void test_computePay(string testName, double hours, double wage)
{
    assert(("hours must be positive"), hours >= 0.0);
    assert(("hours must be reasonable"), hours <= 80.0);
    assert(("wage must be positive"), wage >= 0.0);
    
    cout << testName << ": " << computePay(hours, wage) << endl;
}

class TestCoordinate
{
    TestCoordinate();
};

int main()
{
    test_computePay("Zeroes", 0.0, 0.0);
}


    //assert(("Zeroes Failed", computePay(0.0, 0.0) == 0.0));
    //cout << "Zeroes Passed" << endl;

    //assert(("No Time Failed", computePay(0.0, 8.0) == 0.0));
    //cout << "No Time Passed" << endl;

    //assert(("One Hour Failed", computePay(1.0, 8.0) == 8.0));
    //cout << "One Hour Passed" << endl;

    //assert(("No Wage Failed", computePay(1.0, 0.0) == 0.0));
    //cout << "No Wage Passed" << endl;

    //assert(("Just Under Full Time Failed", computePay(39.0, 10.0) == 390.0));
    //cout << "Just Under Full Time Passed" << endl;

    //assert(("Full Time Failed", computePay(40.0, 10.0) == 400.0));
    //cout << "Full Time Passed" << endl;

    //assert(("One Hour Overtime Failed", computePay(41.0, 10.0) == 415.0));
    //cout << "One Hour Overtime Passed" << endl;

    //assert(("Double Time Failed", computePay(80.0, 10.0) == 1000.0));
    //cout << "Double Time Passed" << endl;

    ///*assert(("Negative Hours Failed", computePay(-1.0, 10.0) > 0.0));
    //cout << "Negative Hours Passed" << endl;*/

    ///*assert(("Negative Wage Failed", computePay(1.0, -8.0) > 0.0));
    //cout << "Negative Wage Passed" << endl;*/

    ///*assert(("Unreasonable Hours Failed", computePay(168.0, 10.0) < 2320.0));
    //cout << "Unreasonable Hours Passed" << endl;*/