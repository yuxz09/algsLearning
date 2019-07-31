#include "DoubleList.hpp"
#include <iostream>
using namespace std;

DoubleList::DoubleList()
{
	head = NULL;
	tail = NULL;
	
}

void DoubleList::addnode(Node* newnode)
{
	if(newnode == NULL)
	{
		return;
	}
	else if(head == NULL)//doublelist is empty
	{
		head = newnode;
		tail = newnode;
		head -> next = tail;
		head -> prev = NULL;
		tail -> next = NULL;
		tail -> prev =head;
	}
	else
	{
		tail -> next = newnode;
		newnode -> prev = tail;
		newnode -> next = NULL;
		tail = newnode;
	}
}

void DoubleList::movetoend(Node* node)
{
	if(node == NULL || node == tail)//node is empty or node at the end
	{
		return;
	}
	else if(node == head)
	{
		node -> next -> prev = NULL;
		head = node -> next;
	}
	else
	{
		node -> next -> prev = node -> prev;
		node -> prev -> next = node -> next;
	}
	node -> prev = tail;
	node -> next = NULL;
	tail -> next = node;
	tail = node;
}

void DoubleList::removehead()
{
	if(!head)
	{
		return;
	}
	Node* temp = head;
	head = head -> next;
	temp -> prev = NULL;
	temp -> next = NULL;
	free(temp);
}

DoubleList::~DoubleList()//destructor, can not have return type
{
	Node* temp = head;
	while(head != NULL)
	{
		head = head -> next;
		//temp.~Node();
		delete temp;
		temp = head;
	}
}

