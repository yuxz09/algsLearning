/*

数组中累积和与最小值的乘积,假设叫做指标A。 给定一个数组,请返回子数组中,指标A最大的值。
也就是所有子数组中的 子数组中最小值与子数组累积和乘积的结果，取最大的那个

现在就开始求假设以每个元素为最小值，以当前位置向左右扩，何时子数组的累积和最大？
假设当前元素下标为i, 找到两边比当前v[i]小的值作为左右边界。
也就是说左右边界内的数字都比v[i]要大，一旦出现比它小的，v[i]就不再是最小的了

 */

#include <iostream>
#include <algorithm>
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

vector<int> getSum(vector<int> v)
{
    vector<int> sum(v.size());
    int temp = 0;
    for(int i = 0; i < v.size(); i++)
    {
        temp += v[i];
        sum[i] = temp;
    }
    return sum;
}


int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(3);
    v.push_back(3);
    v.push_back(4);

    vector<int> sum = getSum(v);

    int l = -1;
    int r = -1;
    int maxres = -1;
    int templ = -1;
    int tempr = -1;
    int temp = -1;
    //如何找左右两边比它小的值
    vector<vector<int> > minRange = MonoStack(v);
    for(int i = 0; i < v.size(); i++)
    {
        l = minRange[i][0];
        r = minRange[i][1];
        if(l == -1 && r != -1)
        {
            templ = sum[i];
            tempr = sum[r-1] - sum[i];
            temp = templ+tempr;
        }
        if(r == -1 && l != -1)
        {
            tempr = sum[v.size()-1] - sum[i-1];
            templ = sum[i-1] - sum[l];
            temp = templ+tempr;
        }
        else if(l == -1 && r == -1)
        {
            continue;
        }
        else if(l != -1 && r != -1)
        {
            temp = sum[r-1] - sum[l];
        }
        maxres = max(maxres, temp*v[i]);
    }
    cout << maxres << endl;
}

