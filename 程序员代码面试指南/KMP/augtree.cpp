/*
二叉树的增、删、改、查
 */
#include "augtree.hpp"
#include <iostream>
#include <assert.h> 
#include <string>
using namespace std;


//init BSTree variables
void initBSTree(struct BSTree* tree)
{
	tree -> cnt = 0;
	tree -> root = NULL;
}

//allocate space for tree, return a new tree
struct BSTree* newBSTree()
{
	struct BSTree* tree = new BSTree;
	assert(tree != NULL);
	initBSTree(tree);
	return tree;
}

/*
用根节点root来代表tree树
将节点加入树，分三种情况：
(1) 树为空，那么当前加入的val是根节点root
(2) val < cur.val
(3) val > cur.val
 */
struct Node* addNode(struct Node* cur, TYPE val)
{
	if(cur == 0)
	{
		struct Node* newnode = new Node;
		newnode -> val = val;
		newnode -> left = NULL;
		newnode -> right = NULL;
		return newnode;
	}
	else if(stoi(val) < stoi(cur->val))//val < cur val
	{
		cur -> left = addNode(cur->left, val);////cur->left
	}
	else if(stoi(val) > stoi(cur->val))//val > cur val
	{
		cur -> right = addNode(cur->right, val);////cur->right
	}
	return cur;
}

//add val to tree
struct BSTree* addBSTree(struct BSTree* tree, TYPE val)
{
	tree -> root = addNode(tree->root, val);
	tree -> cnt++;
	return tree;
}




bool containsBSTree(struct BSTree* tree, TYPE val)
{
	struct Node* curnode = tree -> root;
	while(curnode != NULL)
	{
		if(val < curnode->val)
		{
			curnode = curnode -> left;
		}
		else if(val > curnode->val)
		{
			curnode = curnode -> right;			
		}
		else
		{
			return true;
		}
	}
	return false;
	/*
	if(node == NULL)
	{
		return false;
	}
	else if(val < node->val)
	{
		return containsBSTree(node->left, val);
	}
	else if(val > node->val)
	{
		return containsBSTree(node->right, val);		
	}
	return true;
	*/
}






//return type TYPE 
TYPE leftMost(struct Node* cur)
{
	if(cur -> left == NULL)
	{
		return cur->val;
	}
	return leftMost(cur);
}


struct Node* removeleftMost(struct Node* cur)
{	
	assert(cur != 0);
	if(cur -> left == NULL)//cur is the leftMost child
	{
		struct Node* temp = cur -> right; //可能cur也没有right child那么此时删除这个leftMostchild就没有节点可以代替，变为空
		free(cur);
		return temp;		
	}
	//cur is not the leftMost child
	cur -> left = removeleftMost(cur->left);
	return cur;
}

/*
一个节点的leftmost child, rightmost child值与它最为接近
这里以leftmost child为例
 */
struct Node* removeNode(struct Node* cur, TYPE val)
{
	assert(cur != 0);
	struct Node* tempnode;
	if(cur -> val == val)//cur是要删除的节点，如果有leftmostchild给它赋leftmostchild的值，然后删除leftmostchild
	{
		if(cur->right == NULL)
		{
			tempnode = cur -> left;
			free(cur);
			return tempnode;
		}
		else
		{
			cur -> val = leftMost(cur->right);
			cur->right = removeleftMost(cur->right);
		}
	}
	else if(val < cur -> val)
	{
		cur -> left = removeNode(cur->left, val);
	}
	else
	{
		cur -> right = removeNode(cur->right, val);
	}
	return cur;

}

//return type void
void removeBSTree(struct BSTree* tree, TYPE val)
{
	if(containsBSTree(tree, val) == true)
	{
		tree->root = removeNode(tree->root, val);
		tree -> cnt--;
	}
}












