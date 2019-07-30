#ifndef RANDOMPOOL_HPP
#define RANDOMPOOL_HPP
#include <string>
#include <unordered_map>
using namespace std;

class RandomPool
{
public:
	unordered_map<string, int> keyIndexMap;
	unordered_map<int, string> indexKeyMap;
	int size;

	RandomPool();
	void insertkey(string key);
	void delkey(string key);
	string getRandom();
};

#endif