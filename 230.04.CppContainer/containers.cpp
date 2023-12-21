/*************************************************************
 * 1. Name:
 *      Marcel Pratikto
 * 2. Assignment Name:
 *      Practice 04: Contaiers
 * 3. Assignment Description:
 *      Work with a list and a vector
 * 4. What was the hardest part? Be as specific as possible.
 *      figuring out the iterators
 * 5. How long did it take for you to complete the assignment?
 *      40 minutes
 **************************************************************/


#include "testContainers.h"
#include <string>
#include <list>
using namespace std;

/*****************************
 * ARRAY TO LIST
 *****************************/
list<string> arrayToList(string a[], int num)
{
	list<string> listString;
	for (int i = 0; i < num; ++i)
	{
		listString.push_back(a[i]);
	}
	return listString;
}

/*****************************
 * ARRAY TO LIST BACKWARDS
 *****************************/
list<string> arrayToListBackwards(string a[], int num)
{
	list<string> listString;
	for (int i = 0; i < num; ++i)
	{
		listString.push_front(a[i]);
	}
	return listString;
}

/*****************************
 * LIST TO VECTOR
 *****************************/
vector<string> listToVector(const list<string> & l)
{
	vector<string> vectorString;
	for (auto datum : l)
	{
		vectorString.push_back(datum);
	}
	return vectorString;
}

/*****************************
 * LIST TO VECTOR BACKWARDS
 *****************************/
vector<string> listToVectorBackwards(const list<string>& l)
{
	vector<string> vectorString;
	for (auto rit = l.rbegin(); rit != l.rend(); rit++)
	{
		vectorString.push_back(*rit);
	}
	return vectorString;
}

/*****************************
 * FIND ELEMENT IN VECTOR
 *****************************/
bool findElementInVector(const vector<string> & v, const string& element)
{
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] == element)
			return true;
	}
	return false;
}

/*****************************
 * MAIN
 *****************************/
int main()
{
   TestCollection().run();
   return 0;
}
