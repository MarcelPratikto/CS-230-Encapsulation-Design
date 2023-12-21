// W10-Problem-Set.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
using namespace std;

class Coordinate
{
private:
    bool chessboard[65];
public:
    void set(const char* input)
    {
        int position[2];
        int index = 0;
        for (const char* p = input; *p; ++p)
        {
            switch (*p)
            {
            case 'a':
            case 'A':
            case '1':
                position[index] = 1;
                break;
            case 'b':
            case 'B':
            case '2':
                position[index] = 2;
                break;
            case 'c':
            case 'C':
            case '3':
                position[index] = 3;
                break;
            case 'd':
            case 'D':
            case '4':
                position[index] = 4;
                break;
            case 'e':
            case 'E':
            case '5':
                position[index] = 5;
                break;
            case 'f':
            case 'F':
            case '6':
                position[index] = 6;
                break;
            case 'g':
            case 'G':
            case '7':
                position[index] = 7;
                break;
            case 'h':
            case 'H':
            case '8':
                position[index] = 8;
                break;
            default:
                throw invalid_argument("Please enter a valid position. Ex: 'a1', '1a', 'A1', '1A'");
            }
            ++index;
        }
        int pos = position[0] * position[1];
        chessboard[pos] = 1;
        cout << "chessboard[" << pos << "] successfully filled." << endl;
    }
};

int main()
{
    try
    {
        Coordinate coordinate;
        coordinate.set("a1");
        coordinate.set("1A");
        coordinate.set("AA");
        coordinate.set("c1");
        coordinate.set("e5");
        coordinate.set("h8");
    }
    catch (invalid_argument& e)
    {
        cerr << e.what() << endl;
        return -1;
    }

    return 0;
}
