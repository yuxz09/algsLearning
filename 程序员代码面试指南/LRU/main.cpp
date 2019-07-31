#include "LRU.hpp"
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	LRU lru(2);
//	cout << lru.capacity << endl;
	lru.set("A", 1);
	lru.set("B", 2);
	cout << lru.get("A") << endl;
	lru.set("C", 3);
	cout << lru.get("B") << endl;
	lru.set("D", 4);
	cout << lru.get("A") << endl;
	cout << lru.get("C") << endl;
	cout << lru.get("D") << endl;
//1  2
//2  1
//1  3	
}