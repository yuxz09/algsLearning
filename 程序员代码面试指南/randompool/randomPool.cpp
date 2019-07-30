#include "randomPool.hpp"
#include <unordered_map>
#include <cstdlib>
RandomPool::RandomPool()
{
//	keyIndexMap = new unordered_map<int, string>();
//	indexKeyMap = new unordered_map<string, int>();
	size = 0;
}

void RandomPool::insertkey(string key)
{
	if(keyIndexMap.find(key) == keyIndexMap.end())
	{
		keyIndexMap.insert(make_pair(key, size));
		indexKeyMap.insert(make_pair(size, key));
		size++;
	}
}

/*
这么做的目的是保证map2里面的index是连续的
这样getRandom(),index在map2连续，就可以getrandom key

如果一个map,删掉记录，会出现空值，断开
 */
void RandomPool::delkey(string key)
{
	if(keyIndexMap.find(key) != keyIndexMap.end())
	{
		int delIndex = keyIndexMap.at(key);
		int lastIndex = size - 1;
		string lastKey = indexKeyMap.at(lastIndex);
		keyIndexMap.insert(make_pair(lastKey, delIndex));
		indexKeyMap.insert(make_pair(delIndex, lastKey));
		keyIndexMap.erase(key);
		indexKeyMap.erase(lastIndex);
		size--;
	}
}

string RandomPool::getRandom()
{
	if(size==0)
	{
		return 0;
	}
	int randomIndex = rand() % size;
	return indexKeyMap.at(randomIndex);
}

