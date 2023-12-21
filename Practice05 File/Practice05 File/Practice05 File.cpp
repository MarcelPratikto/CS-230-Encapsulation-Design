/*************************************************************
 * 1. Name:
 *      Marcel Pratikto, Grant Shirley
 * 2. Assignment Name:
 *      Practice 05: File
 * 3. Assignment Description:
 *      Do some stuff with files
 * 4. What was the hardest part? Be as specific as possible.
 *      figuring out fstream
 * 5. How long did it take for you to complete the assignment?
 *      ~1 hour
 *****************************************************************/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const string FILETOUSE = "data.txt";

double readBalance()
{
    double balance;
    // read from file
    ifstream fin;
    fin.open(FILETOUSE);
    // if we can't open file, print message
    // else get value from file
    if (fin.fail())
    {
        cout << "UNABLE TO OPEN " << FILETOUSE << endl;
        balance = 0.0;
    }
    else
    {
        fin >> balance;
    }
    // close file
    fin.close();
    
    return balance;
}

void writeBalance(double balance)
{
    // write to file
    ofstream fout;
    fout.open(FILETOUSE);
    // Try to write to the file
    if (fout.fail())
        cout << "UNABLE TO WRITE BALANCE TO " << FILETOUSE << endl;
    else
    {
        fout << balance;
        cout << "BALANCE SUCCESSFULLY WRITTEN TO " << FILETOUSE << endl;
    }
    fout.close();
}

double updateBalance(double balance)
{
    double change = 0.0;
    cout << "Change: $";
    cin >> change;
    balance += change;
    
    return balance;
}

void displayBalance(double balance)
{
    cout << "Account balance: $" << balance << endl;
}

int main()
{
    double balance = readBalance();
    displayBalance(balance);
    balance = updateBalance(balance);
    displayBalance(balance);
    writeBalance(balance);
}
