#ifndef MESSAGEBOX_HPP
#define MESSAGEBOX_HPP
#include <map>
//#include <string>
using namespace std;



struct Node
{
	int index;
	Node* next;
	Node(int i)
	{
		index = i;
		next = NULL;
	}
};


class messageBox
{
private:
	map<int, Node*> headmap;
	map<int, Node*> tailmap;
	int waitNum;

public:
	messageBox();
	void receive(int num);
	void print();
};
#endif


