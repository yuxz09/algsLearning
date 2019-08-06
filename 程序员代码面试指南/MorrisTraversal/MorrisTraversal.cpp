/*
Morris Traversal方法遍历二叉树（非递归，不用栈，O(1)空间）
实现二叉树的前序（preorder）、中序（inorder）、后序（postorder）遍历有两个常用的方法：
一是递归(recursive)，二是使用栈实现的迭代版本(stack+iterative)。
这两种方法都是O(n)的空间复杂度(递归本身占用stack空间或者用户自定义的stack)所以不满足要求。

核心：
让下层到上层有指针，具体是通过让底层节点指向null的空闲指针指回上层的某个节点，从而完成下层到上层的移动。



题目:
给定一颗二叉树的头节点head,完成二叉树的先序、中序和后序遍历。如果二叉树的节点数为N,要求时间复杂度为O(N),额外空间复杂度为O(1)。


步骤:
假设来到当前节点cur， 开始时cur来到头节点位置
(1)如果cur没有左孩子，cur向右移动(cur = cur.right)
(2)如果cur有左孩子，找到左子树上最右的节点mostRight;
	b.如果mostRight的右指针指向cur,让其指向null,然后cur向右移动(cur = cur.right)
	a.如果mostRight的右指针指向空，让其指向cur, 然后cur向左移动(cur = cur.left);
(3)如果cur为空，循环终止

 */
#include "augtree.hpp"/////
#include <iostream>
#include <string>
using namespace std;



void printInorder(struct Node* node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    cout << node->val << " ";

    /* now recur on right child */
    printInorder(node->right);
}

struct Node* reverseEdge(struct Node* curnode)
{
    struct Node* pre = NULL;
    struct Node* next = NULL;
    while(curnode != NULL)
    {
        next = curnode->right;
        curnode->right = pre;
        pre = curnode;
        curnode = next;
    }
    return pre;//rightEdge最后一个节点
}

void printEdge(struct Node* curnode)
{
    struct Node* tail = reverseEdge(curnode);
    struct Node* temp = tail;
    while(temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp -> right;
    }
    reverseEdge(tail);
}




void MorrisTraversal(struct Node* head)
{
    struct Node* curnode = head;////保存头节点，防止之后改动，影响整个树的根节点head
    if(curnode == NULL)
    {
        return;
    }
    while(curnode != NULL)
    {
        if(curnode -> left == NULL)
        {
            //     cout << curnode -> val << endl; 中序遍历  先序遍历
            curnode = curnode -> right;

        }
        else//curnode -> left != NULL
        {
            struct Node* tempnode = curnode->left;
            while(tempnode->right != NULL && tempnode -> right != curnode)
            {
                tempnode = tempnode->right;
            }
            //如果是有左子树但是是一边倒的结构，全部都是左孩子，那么当前节点的下一个左孩子就是当前节点左子树的 最右 节点
            if(tempnode -> right == NULL)
            {
                tempnode -> right = curnode;
          //      cout << curnode -> val << endl;//先序遍历
                curnode = curnode -> left;
            }
            else
            {
                tempnode -> right = NULL;
                printEdge(curnode->left);
                //cout << curnode -> val << endl;  中序遍历
                curnode = curnode -> right;
            }
        }
    }

    printEdge(head);
}

/*

中序遍历: 左-根-右
打印：发现curnode没有左子树的时候，打印curnode,然后向右移动
     当发现curnode左子树的最右节点指向curnode，也就是第二次来到curnode，说明左子树已经遍历完了，左子树最右节点沿着指针返回, curnode右移前打印curnode
     综上所述，curnode"根"节点是在右移前再打印，左子树已经打完，所以是中序遍历，左-根-右

先序遍历：根-左-右
打印：如果curnode没有左子树，向右移动前，必须先打印curnode"根"节点
	 刚发现curnode，有左子树，立马打印，不要等到curnode左子树最右节点指向curnode，也就是某个tempnode右指针右移会回到curnode

后序遍历：左-右-跟
打印：在第二次移动到curnode的时候，打印curnode左子树的右边界，调用PrintEdge(curnode->left)
	 其实这个PrintEdge(curnode->left)如果curnode->left没有右孩子，就打印curnode->left本身，可以确定的是
	 当回到curnode时，curnode的左子树已经打印完了
	 最后打印整个树的右边界，PrintEdge(tree->root);



*/


int main()
{
    struct BSTree* tree = newBSTree();
    tree = addBSTree(tree, 10);
    tree = addBSTree(tree, 6);
    tree = addBSTree(tree, 16);
    tree = addBSTree(tree, 3);
    tree = addBSTree(tree, 8);
    tree = addBSTree(tree, 2);
    tree = addBSTree(tree, 1);
    tree = addBSTree(tree, 4);
    tree = addBSTree(tree, 5);
    tree = addBSTree(tree, 7);
    tree = addBSTree(tree, 9);
    tree = addBSTree(tree, 12);
    tree = addBSTree(tree, 11);
    tree = addBSTree(tree, 20);

    MorrisTraversal(tree->root);
    //   printInorder(tree->root);
}


