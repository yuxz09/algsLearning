#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
using std::string;

class Node
{
public:
	string key;
	int val;
	Node* prev;
	Node* next;

//	Node(string str, int value, Node* prevnode, Node* nextnode); 
	Node();
	Node(string str, int value);
	~Node();

};
#endif