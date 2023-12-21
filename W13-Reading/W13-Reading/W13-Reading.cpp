#include <iostream>
using namespace std;

/****************************
 * MONEY: A class to store money
 ****************************/
class Money
{
public:
    // Constructor
    Money(int amount) : amount(amount) {}

    // Display
    virtual void display() const
    {
        cout << amount;
    }

protected:
    // One attribute, the amount.
    int amount;
};

/****************************
 * DOLLARS: US Dollars
 ****************************/
class Dollars : public Money
{
public:
    // Constructor
    Dollars(int amount) : Money(amount) {}

    // Display
    virtual void display() const
    {
        cout << "$"
            << (double)amount / 100.0;
    }
};

/****************************
 * YEN: Japanese Yen
 ****************************/
class Yen : public Money
{
public:
    // Constructor
    Yen(int amount) : Money(amount) {}

    // Display
    virtual void display() const
    {
        cout << "Yen "
            << amount;
    }
};

/****************************
 * MAIN
 ****************************/
int main()
{
    Money money(100);
    Dollars dollars(50);
    Yen yen(70);
    Money monies[] = {money, dollars, yen};
    for (auto p : monies)
    {
        p.display();
        cout << endl;
    }

    Money* p_monies[] = { &money, &dollars, &yen };
    for (auto p : p_monies)
    {
        p->display();
        cout << endl;
    }
}