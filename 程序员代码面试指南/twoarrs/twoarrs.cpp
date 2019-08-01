/*
给定两个有序数组arr1和arr2,再给定一个整数k,返回来自arr1和arr2的两个数相加和最 大的前k个,两个数必须分别来自两个数组。
【举例】
arr1=[1,2,3,4,5],arr2=[3,5,7,9,11],k=4。 返回数组[16,15,14,14]
【要求】
时间复杂度达到 O(klogk)
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using std::vector;
using std::priority_queue;
using std::cout;
using std::endl;
using std::min;

struct node
{
	int index1;
	int index2;
	int sum;

};

struct cmp
{
	bool operator() (const node& node1, const node& node2) const
	{
		return node2.sum > node1.sum;/////////
	}
};



vector<node> summaxK(vector<int> v1, vector<int> v2, int k)
{
	vector<node> collect;
	if(v1.size() == 0 || v2.size() == 0 || k == 0)
	{
		return collect;
	}
	int maxsz = v1.size() * v2.size();
	k = min(k, maxsz);

	vector<vector<bool> > v(v1.size(), vector<bool>(v2.size()));

	int i1 = v1.size()-1;
	int i2 = v2.size()-1;
	int cnt = 0;

	priority_queue<node, vector<node>, cmp> pq;
	node tempnode;
	tempnode.index1 = i1;
	tempnode.index2 = i2;
	tempnode.sum = v1[i1] + v2[i2];

	pq.push(tempnode);
	v[i1][i2] = true;



	while(cnt < k)
	{
		tempnode = pq.top();
//		cout << tempnode.sum << endl;
		collect.push_back(tempnode);
		cnt++;
		pq.pop();
		i1 = tempnode.index1;
		i2 = tempnode.index2;
		if(v[i1-1][i2] == false && i1-1>=0)
		{
			v[i1-1][i2] = true;
			tempnode.index1 = i1-1;
			tempnode.index2 = i2;
			tempnode.sum = v1[i1-1]+v2[i2];
  //          cout << "i1: " << i1 << " i2: " << i2 << " sum: " <<  tempnode.sum << endl;
			pq.push(tempnode);

		}
		if(v[i1][i2-1] == false && i2-1>=0)
		{
			v[i1][i2-1] = true;
			tempnode.index1 = i1;
			tempnode.index2 = i2-1;
			tempnode.sum = v1[i1]+v2[i2-1];
   //         cout << "i1: " << i1 << "i2: " << i2 << " sum: " << tempnode.sum << endl;
			pq.push(tempnode);
		}
	}
//	cout << collect[0].sum << endl;
	return collect;
}

int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);


	vector<int> v2;
	v2.push_back(3);
	v2.push_back(5);
	v2.push_back(7);
	v2.push_back(9);
	v2.push_back(11);

	vector<node> tempvect = summaxK(v1, v2, 4);
	for(int i = 0; i < tempvect.size(); i++)
	{
		cout << tempvect[i].sum << endl;
	}
	return 0;
}
