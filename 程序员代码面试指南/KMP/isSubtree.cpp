/*
给定两颗二叉树T1和T2,怎么知道是否T1的某棵子树和T2相等。并返回结果
 */
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
	string res = cur->val + "!";
	res += serialPre(cur->left);
	res += serialPre(cur->right);
	return res;
}

int* getNext(string str)
{
	static int next[1000000] = {0};////

	//强行规定
	next[0] = -1;//////
	next[1] = 0;/////

	int i = 2;
	int cn = 0;

	while(i < str.length())
	{
		if(str[i-1] == str[cn])
		{
			//cn为i-1位置上的最长前缀长度的后一个位置
			//因为相等，所以cn作为最长前缀长度的后一个位置需要延长
			next[i] = cn + 1;/////
			cn = cn + 1;////
			i++;////
		}
		else if(cn == 0)
		{
			next[i] = 0;
			i++;///
		}
		else
		{
			cn = next[cn];//
		}
	}
	return next;
}

int kmp(string str1, string str2)
{
	int *next = getNext(str2);
	if(str1.length() < str2.length())
	{
		return false;
	}
	int i = 0;
	int j = 0;
	for(i = 0, j = 0; i < str1.length() && j < str2.length(); )
	{
		if(str1[i] == str2[j])
		{
			i++;
			j++;
		}
		else if(next[j] == -1)//str2的j位置没有前缀与后缀相等的情况 或者说 j == 0
		{
			i++;
		}
		else
		{
			j = next[j];
		}
	}
	if(j == str2.length())
	{
		return i - j;
	}
	else
	{
		return -1;
	}
}

bool isSubtree(string s1, string s2)
{
	if(kmp(s1, s2) == -1)
	{
		return false;
	}
	return true;
}

int main()
{
	struct BSTree* tree1 = newBSTree();
	tree1 = addBSTree(tree1, "4");
	tree1 = addBSTree(tree1, "2");
	tree1 = addBSTree(tree1, "6");
	tree1 = addBSTree(tree1, "1");
	tree1 = addBSTree(tree1, "3");
	tree1 = addBSTree(tree1, "5");
	tree1 = addBSTree(tree1, "7");

	struct BSTree* tree2 = newBSTree();
	tree2 = addBSTree(tree2, "6");
	tree2 = addBSTree(tree2, "5");
	tree2 = addBSTree(tree2, "7");

	string s1 = serialPre(tree1->root);
	cout << s1 << endl;
	string s2 = serialPre(tree2->root);
    cout << s2 << endl;

	cout << isSubtree(s1, s2) << endl;


}