/*
单调栈

无重复值版本

在数组中想找到一个数,左边和右边比这个数 小 、且离这个数  最近  的位置。
如果对每一个数都想求这样的信息,能不能整体代价达到O(N)?需要使用到单调栈结构

背后的逻辑：
a = stack.top();
b = i;新读到vector的下标

a...b中
当v[b] < v[a] 为什么b是a的右边离a最近且比b小的?
v[b] < v[a] 满足 小
ib > ia 满足 在右边
关于 最近
假设a...b中存在:
(1)比b小的: 那么a一定被弹出来过了，轮不到出现需要比较v[b], v[a]
(2)比a大，比b小的: 那么这个比a大，比b小的数字下标c会在a的上面，如果说在这个数字c在之后被弹出，
那么被弹出的条件一定是有一个数字介于c...b之间，假设下标是d,
那么c被弹出一定是因为，v[d] < v[c], 所以d会被加入stack, 或者说只要任何一个数字在b之前到来，
那么一定只要c被弹出，一定会加入新的数字，不是c就是其他数字，轮不到a..b有比较的机会。

综上所述a...b中，出现的数字一定都比b大，所以b是a的右边离a最近的数字
所以当还有数字可以压入stack的时候，当出现v[s.top()] > v[i]就开始pop
所以可以填写pop的tempindex的右边最近比它小的下标，i

并且tempindex的左边最近比它小的下标，是pop后的s.top()
a = s.top()
b = tempindex
如果a...b之间还有更小的，比v[a]更小的，a一定会被pop掉
所以v[a]就是b左边最近最小的

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


vector<vector<int> > MonoStack(vector<int> v)
{
    int n = v.size();
    //declare N*2 2d-vector
    vector<vector<int> > res(v.size(), vector<int>(2));
    int left = -1;
    int right = -1;
    int temp = -1;

    stack<int> s;
    for(int i = 0; i < v.size(); i++)
    {
        if(!s.empty() && v[i]<v[s.top()])//v[i] < v[s.top()] 只要stack顶部的数字大于当前要加入的数字就一直pop
        {
            while(!s.empty() && v[s.top()] > v[i])
            {
                temp = s.top();//承接弹出的这条记录的下标
                s.pop();
                //每次pop前，统计当前位置的左、右最邻近最小值
                if(s.empty())
                {
                    left = -1;
                }
                else// s.size() > 1
                {
                    left = s.top();
                }
                right = i;
                res[temp][0] = left;
                res[temp][1] = right;
            }
        }
        s.push(i);
    }

    while(!s.empty())
    {
        temp = s.top();
        s.pop();
        if(s.empty())
        {
            res[temp][0] = -1;
        }
        else
        {
            res[temp][0] = s.top();
        }
        res[temp][1] = -1;
    }

    return res;
}

int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(0);
    v.push_back(5);
    v.push_back(6);

    vector<vector<int> > res = MonoStack(v);

    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
