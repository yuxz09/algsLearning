//反序列化
#include "augtree.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <queue>


using namespace std;


//4!2!6!1!3!5!7!#!#!#!#!#!#!#!#!
//每一次截取到感叹号位置，所以下一次截取str要么是数字要么是#
string extractStr(string &s)
{
    int index = 0;
    int pos = s.find('!');
    string temp = s.substr(index, pos);       
    s = s.substr(pos+1, s.length()+1); 
    return temp;  
}

struct Node* reconLevelStr(string& s)
{
    int index = 0;
    string temp = extractStr(s);//提取数字
  
    //declare queue
    queue<Node*> q;
    struct Node* head = new Node;
    head = NULL;
    head = addNode(head, temp);  
    q.push(head); 

    while(!q.empty())
    {
        index++;        
        struct Node* cur = q.front();
        temp = extractStr(s);

        if(temp != "#")
        {
            cur -> left = addNode(cur->left, temp);
        }
        else
        {
            cur -> left = NULL;
        }
        temp = extractStr(s);
        if(temp != "#")
        {
            cur -> right = addNode(cur->right, temp);
        }
        else
        {
            cur -> right = NULL;
        }

        q.pop();

        if(cur -> left != NULL)
        {
            q.push(cur->left);
        }
        if(cur -> right != NULL)
        {
            q.push(cur->right);
        }
    }
    return head;
}

void levelOrder(struct Node* cur)
{
    queue<Node*> q;
    string str = "";
    q.push(cur);
    while(!q.empty())
    {
        struct Node* temp = q.front();
        q.pop();
        cout << temp -> val << endl;
        q.push(temp->left);
        q.push(temp->right);
    }

}


int main()
{
    string str = "4!2!6!1!3!5!7!#!#!#!#!#!#!#!#!";
    int n = str.length();

    struct BSTree* tree = newBSTree();

    tree -> root = reconLevelStr(str);


    cout << "-------------------------" << endl;
    levelOrder(tree->root);
}


/*

while(!q.empty())
{
    cout << q.front() << endl;
    q.pop();  //queue pop()从队首弹出
}

*/




