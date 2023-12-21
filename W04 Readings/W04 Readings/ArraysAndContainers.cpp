#include "ArraysAndContainers.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>

void ArraysAndContainers::arr()
{
    // create an array of strings
    std::string data[] = {
        "alpha", "beta", "gamma", "delta", "epsilon", "zeta"
    };

    std::cout << "data[2]: " << data[2] << std::endl;

    for (auto datum : data)
    {
        std::cout << datum << std::endl;
    }
}

void ArraysAndContainers::vec()
{
    // create a vector of strings
    std::vector<std::string> data;
    for (int i = 0; i < 6; ++i)
    {
        std::cout << "Enter a word: ";
        std::string temp;
        std::cin >> temp;
        data.push_back(temp);
    }
    std::cout << "Size of vector: " << data.size() << std::endl;

    std::cout << "\nITERATE USING INDEX" << std::endl;
    for (int i = 0; i < data.size(); ++i)
    {
        std::cout << data[i] << std::endl;
    }
    std::cout << "\nITERATE USING ITERATOR" << std::endl;
    for (auto datum : data)
    {
        std::cout << datum << std::endl;
    }
    // clear the vector
    data.clear();
}

void ArraysAndContainers::li()
{
    // create a list of strings
    std::list<std::string> data;

    // create an iterator pointing to the first element
    //auto it = data.begin();

    for (int i = 0; i < 6; ++i)
    {
        std::cout << "Enter a word: ";
        std::string temp;
        std::cin >> temp;
        data.push_back(temp);
    }
    std::cout << "Size of list: " << data.size() << std::endl;

    // add two elements to the front of the list
    data.push_front("one");
    data.push_front("two");

    std::cout << "\nITERATE USING ITERATOR" << std::endl;
    for (auto datum : data)
    {
        std::cout << datum << std::endl;
    }

    // pop the first element
    data.pop_front();
    // pop the last element
    data.pop_back();

    std::cout << "\nITERATE USING ITERATOR" << std::endl;
    for (auto datum : data)
    {
        std::cout << datum << std::endl;
    }
    // clear the vector
    data.clear();
}