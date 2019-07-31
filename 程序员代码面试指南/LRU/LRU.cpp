#include "LRU.hpp"

#include <unordered_map>

LRU::LRU(int sz)
{
	capacity = sz;
	cnt = 0;
}

void LRU::set(string str, int num)
{
	if(keyNodeMap.find(str) == keyNodeMap.end())//not find string
	{
		//加入keyNodeMap
		Node* newnode = new Node;
		newnode -> key = str;
		newnode -> val = num;		
		keyNodeMap.insert({str, newnode});

		//加入doublelinkedlist
		list.addnode(newnode);
		cnt++;
		if(cnt > capacity)
		{
			keyNodeMap.erase(list.head->key);//删除最不常使用的,//删除double linkedlist头结点
			list.removehead();//去掉头结点
		}
	}
	else//find the key, replace the value
	{
		keyNodeMap[str]->val = num;
		list.movetoend(keyNodeMap[str]);
	}
}

int LRU::get(string str)
{
	if(keyNodeMap.find(str) != keyNodeMap.end())//find the key
	{
		list.movetoend(keyNodeMap[str]);
		return (keyNodeMap[str]->val);
	}
	else
	{
		return -1;
	}
}

LRU::~LRU()
{
	list.~DoubleList();
}


