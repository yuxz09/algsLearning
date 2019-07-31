#include "DoubleList.hpp"//also include "Node.hpp"
#include <unordered_map>
#ifndef LRU_HPP
#define LRU_HPP
using namespace std;
//双向链表记录头，尾指针，所以容易更新新的节点
class LRU
{
public:
	unordered_map<string, Node*> keyNodeMap;//hashtable
	DoubleList list;
	int capacity;
	int cnt;

	LRU(int sz);
	void set(string str, int num);
	int get(string str);
	~LRU();
};
#endif