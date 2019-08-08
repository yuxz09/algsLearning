#ifndef AUGTREE_HPP
#define AUGTREE_HPP
#include <string>
using std::string;


//把关于struct Node, struct BSTree
typedef string TYPE;

struct Node
{
	TYPE val;
	struct Node* left;
	struct Node* right;
};

//BST: binary search tree
struct BSTree
{
	struct Node* root;
	int cnt;//tree size
};

//int compare(TYPE left, TYPE right);
void initBSTree(struct BSTree* tree);
struct BSTree* newBSTree();
struct Node* addNode(struct Node* cur, TYPE val);
struct BSTree* addBSTree(struct BSTree* tree, TYPE val);
bool containsBSTree(struct BSTree* tree, TYPE val);
TYPE leftMost(struct Node* cur);
struct Node* removeleftMost(struct Node* cur);
struct Node* removeNode(struct Node* cur, TYPE val);
void removeBSTree(struct BSTree* tree, TYPE val);



#endif