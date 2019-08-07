//反序列化
#include "augtree.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <queue>


using namespace std;


//4!2!1!##3!##6!5!##7!##

struct Node* reconPreStr(string& s)
{
    int i = 0;
    if(s[i] == '#' || s[i] == '!')
    {
        i++;
        s = s.substr(i, s.length()+1);
        return NULL;
    }

    //只提取数字
    int pos = s.find('!');//找到感叹号的位置
    string temp = s.substr(i, pos);//提取数字，不包括感叹号位置
    s = s.substr(pos+1, s.length()+1);
    struct Node* head = new Node;
    head = NULL;
    head = addNode(head, temp);
    head -> left = reconPreStr(s);
    head -> right = reconPreStr(s);
    return head;
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
    string str = "4!2!1!##3!##6!5!##7!##";
    int n = str.length();

    struct BSTree* tree = newBSTree();

    tree -> root = reconPreStr(str);
    cout << "-------------------------" << endl;
    preOrder(tree->root);
}

/*

while(!q.empty())
{
    cout << q.front() << endl;
    q.pop();  //queue pop()从队首弹出
}

*/
