#include "Node.hpp"
#include <iostream>
using std::string;

Node::Node()
{
	
}

Node::Node(string str, int value)
{
	key = str;
	val = value;
//	prev = prevnode;
//	next = nextnode;
}

Node::~Node()
{
	prev = NULL;
	next = NULL;
}
