/*
给定一个无序整型数组 arr,找到数组中未出现的最小正整数。要求时间复杂度O(N),额 外空间复杂度O(1)


有效区  indexL = -1
无效区  indexR = arr.length()

无效情况：
情况一： <= L+1
情况二： > R
情况三：位置不对，arr[6] = 23, arr[22] = 23

 */

#include <iostream>
#include <vector>
using namespace std;


void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int minPosNum(vector<int> vect)
{
    int l = 0;
    int r = vect.size();
    while(l < r)
    {
        if(vect[l] == l+1)
        {
            l++;//有效区扩大，右移
        }
        else if(vect[l] <= l || vect[l] > r || vect[vect[l]-1] == vect[l])
        {
            r--;//无效区扩大，左移
            swap(vect[l], vect[r]);
        }
        else
        {
            swap(vect[l], vect[vect[l]-1]);
        }
    }
    return l+1;
}

int main()
{
    vector<int> vect;
    vect.push_back(-1);
    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(4);
    cout << minPosNum(vect) << endl;


    vector<int> vect2;
    vect2.push_back(1);
    vect2.push_back(2);
    vect2.push_back(3);
    vect2.push_back(4);
    cout << minPosNum(vect2) << endl;
}
