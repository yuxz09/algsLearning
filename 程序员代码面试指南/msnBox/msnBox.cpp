#include "messageBox.hpp"
#include <iostream>
#include <map>
using namespace std;



messageBox::messageBox()
{
	map<int, Node*> headmap;
	map<int, Node*> tailmap;
	waitNum = 1;
}

void messageBox::receive(int num)
{
	if(num < 1)
	{
		return;
	}
	Node* cur = new Node(num);
	headmap.insert(std::pair<int, Node*>(num, cur));
	tailmap.insert(std::pair<int, Node*>(num, cur));

//找到上一个尾节点
	if(tailmap.find(num-1) != tailmap.end())
	{
		tailmap.at(num-1) -> next = cur;
		tailmap.erase(num-1);
//		headmap.at(num-1)->next = cur;
		headmap.erase(num);
	}
//找到下一个头节点
	if(headmap.find(num+1) != headmap.end())
	{
		cur -> next = headmap.at(num+1);
		headmap.erase(num+1);
//		cur -> next = tailmap.at(num+1);
		tailmap.erase(num);
	}
//	cout << "waitNum: " << waitNum << endl;
	if(num == waitNum)
	{
		print();
	}
}

void messageBox::print()
{
	struct Node* tempnode = headmap.at(waitNum);
	headmap.erase(waitNum);
	while(tempnode != NULL)
	{
		cout << tempnode -> index << endl;
		tempnode = tempnode -> next;
		waitNum++;
	}
	tailmap.erase(--waitNum);
	waitNum++;
}

int main()
{
	messageBox msnbox;
	msnbox.receive(2);
	msnbox.receive(1);

	msnbox.receive(4);
	msnbox.receive(5);
	msnbox.receive(7);
	msnbox.receive(8);
	msnbox.receive(6);
	msnbox.receive(3);
	msnbox.receive(9);
	msnbox.receive(10);
	msnbox.receive(12);
	msnbox.receive(13);
	msnbox.receive(11);
}

