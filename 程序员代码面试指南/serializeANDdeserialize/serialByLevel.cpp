#include "augtree.hpp"
#include <iostream>
#include <string>
#include <queue>
using namespace std;

string serialLevel(struct Node* cur)
{
	if(cur == NULL)
	{
		return "#";
	}
	string res = cur->val + "!";
	queue<Node*> q;
	q.push(cur);
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		if(cur->left != NULL)
		{
			res += cur->left->val + "!";
			q.push(cur->left);
		}
		else
		{
			res += "#!";
		}
		if(cur->right != NULL)
		{
			res += cur->right->val + "!";
			q.push(cur->right);
		}
		else
		{
			res += "#!";
		}
	}
	return res;
}

void preOrder(struct Node* cur)
{
    if(cur == NULL)
    {
        return;
    }
    cout << cur -> val << endl;
    preOrder(cur->left);
    preOrder(cur->right);
}


int main()
{
	struct BSTree* tree = newBSTree();
	tree = addBSTree(tree, "4");
	tree = addBSTree(tree, "2");
	tree = addBSTree(tree, "6");
	tree = addBSTree(tree, "1");
	tree = addBSTree(tree, "3");
	tree = addBSTree(tree, "5");
	tree = addBSTree(tree, "7");
    preOrder(tree->root);
	cout << serialLevel(tree->root) << endl;
}
