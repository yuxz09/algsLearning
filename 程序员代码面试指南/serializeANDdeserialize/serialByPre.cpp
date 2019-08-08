#include "augtree.hpp"
#include <iostream>
#include <string>
using namespace std;

string serialPre(struct Node* cur)
{
	if(cur == NULL)
	{
		return "#";
	}
	string res = to_string(cur->val)  + "!";
	res += serialPre(cur->left);
	res += serialPre(cur->right);
	return res;
}

int main()
{
	struct BSTree* tree = newBSTree();
	tree = addBSTree(tree, 4);
	tree = addBSTree(tree, 2);
	tree = addBSTree(tree, 6);
	tree = addBSTree(tree, 1);
	tree = addBSTree(tree, 3);
	tree = addBSTree(tree, 5);
	tree = addBSTree(tree, 7);
	cout << serialPre(tree->root) << endl;
}
