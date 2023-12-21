// W05 Readings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void writeVector (char* fileName, vector<int> vec)
{
    /*cout << fileName << endl;
    cout << vec[0] << endl;*/

    // write to file
    ofstream fout;
    fout.open(fileName);
    // Try to write to the file
    if (fout.fail())
        cout << "fout ERROR!\n";
    else
    {
        for (auto dat : vec)
        {
            fout << dat << "\n";
        }
    }
    fout.close();
}

vector<int> readVector(char* fileName)
{
    vector<int> vec;
    // read from file
    ifstream fin;
    fin.open("file.txt");
    if (fin.fail())
        cout << "fin ERROR!\n";
    else
    {
        int num;
        while (fin >> num)
            vec.push_back(num);
    }
    fin.close();
    return vec;
}

int main()
{
    /*
    string a = "C++";
    int b = 1985;
    double c = 2.71828;

    // write to file
    ofstream fout;
    fout.open("file.txt");
    // Try to write to the file
    if (fout.fail())
        cout << "fout ERROR!\n";
    else
    {
        fout << a << endl;
        fout << b << endl;
        fout << c << endl;
    }
    fout.close();

    // read from file
    ifstream fin;
    fin.open("file.txt");
    if (fin.fail())
        cout << "fin ERROR!\n";
    else
    {
        string line;
        while (getline(fin, line))
            cout << line << endl;
    }
    fin.close();
    */

    vector<int> vec;
    for (int i = 1; i <= 10; ++i)
    {
        vec.push_back(i);
    }
    char fileName[] = "file.txt";
    writeVector(fileName, vec);

    vector<int> vec1;
    vec1 = readVector(fileName);
    for (auto num : vec1)
        cout << num << endl;
}
