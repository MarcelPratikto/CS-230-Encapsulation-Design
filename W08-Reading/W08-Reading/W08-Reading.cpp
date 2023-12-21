// W08-Reading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Position{
private:
    char position;
public:
    Position()
    {
        position = 0;
    }

    int getRow()
    {
        return (int)position / 8;
    }

    int getCol()
    {
        return (int)position % 8;
    }

    void set(int row, int col)
    {
        if (row < 1)
            row = 0;
        if (row > 8)
            row = 8;
        if (col < 1)
            col = 0;
        if (col > 8)
            col = 8;
        position = row * 8 + col;
    }

    void display()
    {
        cout << "row: " << this->getRow()
            << " col: " << this->getCol() << endl;
    }
};

// check if rows, cols
// corresponds to correct position
bool checkPos(Position* pos, char row, char col)
{
    if (pos->getRow() == row)
        if (pos->getCol() == col)
            return true;
    return false;
}

// check if position is within bounds
bool checkLimit(Position* pos)
{
    char row = pos->getRow();
    char col = pos->getCol();
    if (row >=1 && row <= 8)
        if (col >= 1 && col <= 8)
            return true;
    return false;
}

// print result from test
void printResult(string testName, bool b)
{
    if (b == true)
        cout << testName << ": Success" << endl;
    else
        cout << testName << ": Fail" << endl;
}

int main()
{
    /*
    *   Test robustness of Position at the: Tested level
    * 
    *   Valid chess board positions
    * 
    *   57  58  59  60  61  62  63  64      8
    *   49  50  51  52  53  54  55  56      7
    *   41  42  43  44  45  46  47  48      6
    *   33  34  35  36  37  38  39  40      5
    *   25  26  27  28  29  30  31  32      4
    *   17  18  19  20  21  22  23  24      3
    *   9   10  11  12  13  14  15  16      2
    *   1   2   3   4   5   6   7   8       1
    *                                       ^ rows
    *   1   2   3   4   5   6   7   8       < cols
    */
    
    // check if row 4 col 4 == 28
    Position pos;
    pos.set(4, 4);
    printResult("Check Output", checkPos(&pos, 4, 4));

    // What happens if we set position to 0?
    pos.set(0, 0);
    printResult("Check Limit Zero", checkLimit(&pos));

    // What happens if position is greater than 64?
    pos.set(9, 9);
    printResult("Check Limits Over Boundaries", checkLimit(&pos));
}


/*double* values;
    int num;

    cout << "number of values to store: ";
    cin >> num;

    values = new double[num];

    for (int i = 0; i < num; ++i)
    {
        cout << "double to store in values: ";
        cin >> values[i];
    }

    for (int i = 0; i < num; ++i)
    {
        cout << "values[" << i << "]: " << values[i] << endl;
    }

    delete[] values;*/
