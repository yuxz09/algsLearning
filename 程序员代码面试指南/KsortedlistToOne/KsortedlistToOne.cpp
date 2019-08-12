/*
给定k个有序链表的头节点,怎么把他们merge成一个有序的链表。
 */
#include <iostream>
#include <queue>//using std::priority_queue
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int value)
    {
        val = value;
    }
};

struct cmp
{
    bool operator()(Node* node1, Node* node2)
    {
        return node1->val > node2->val;
    }
};


Node* KsortedlistToOne(vector<Node*> vect)
{
    priority_queue<Node*, vector<Node*>, cmp> minheap;
    for(int i = 0; i < vect.size(); i++)
    {
        if(vect[i] != NULL)
        {
            minheap.push(vect[i]);
        }
    }
    struct Node* head = NULL;
    struct Node* pre = NULL;
    while(!minheap.empty())
    {
        struct Node* cur = minheap.top();
        cout << cur -> val << endl;
        minheap.pop();
        if(head == NULL)
        {
            head = cur;
        }
        if(pre != NULL)
        {
            pre -> next = cur;
        }
        pre = cur;
        if(cur -> next != NULL)
        {
            minheap.push(cur->next);
        }
    }
    return head;
}



int main()
{
    struct Node* node1 = new Node(1);
    node1 -> next = NULL;
    struct Node* node2 = new Node(14);
    node1 -> next = NULL;
    struct Node* node3 = new Node(3);
    struct Node* node4 = new Node(8);

    node3 -> next = node4;
    node4 -> next = NULL;

    struct Node* node5 = new Node(2);
    struct Node* node6 = new Node(26);
    node5 -> next = node6;
    node6 -> next = NULL;

    struct Node* node7 = new Node(5);
    node7 -> next = NULL;

    struct Node* node8 = new Node(4);
    node8 -> next = NULL;

    vector<Node*> v;
    v.push_back(node1);
    v.push_back(node2);
    v.push_back(node3);

//    v.push_back(node4);
    v.push_back(node5);
 //   v.push_back(node6);
    v.push_back(node7);
    v.push_back(node8);


    struct Node* res = KsortedlistToOne(v);

    while(res != NULL)
    {
        cout << res -> val << endl;
        res = res -> next;
    }


}

