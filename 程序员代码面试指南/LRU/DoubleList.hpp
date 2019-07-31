#include "Node.hpp"
#ifndef DOUBLELIST_HPP
#define DOUBLELIST_HPP

class DoubleList
{
public:
	Node* head;
	Node* tail;
	DoubleList();
	void addnode(Node* newnode);
	void movetoend(Node* node);
	void removehead();
	~DoubleList();

	
};
#endif