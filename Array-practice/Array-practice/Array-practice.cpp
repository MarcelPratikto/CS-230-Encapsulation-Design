// Array-practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
using namespace std;

class LRUCache {
private:
    vector<int> _cache;
public:
    LRUCache(int capacity) {
        _cache.resize(capacity);
        /*for (int i = 0; i < capacity; ++i)
        {
            _cache.push_back(0);
        }*/
    }

    int get(int key) {
        return _cache[key];
    }

    void put(int key, int value) {
        _cache[key] = value;
    }

    int size() {
        return _cache.size();
    }
};

int main()
{
    LRUCache* cache = new LRUCache(3);
    cache->put(1, 1);
    cache->put(2, 2);

    for (int i = 0; i < cache->size(); ++i)
    {
        cout << "cache[" << i << "]: " << cache->get(i) << endl;
    }
    
}
