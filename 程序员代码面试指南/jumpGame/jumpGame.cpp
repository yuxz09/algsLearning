#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int jump(vector<int> vect)
{
	if(vect.size() == 0)
	{
		return 0;
	}
	int cur = 0;
	int next = 0;
	int jump = 0;
	for(int i = 0; i < vect.size(); i++)
	{
		if(i > cur)//需要跳
		{
			jump++;
			cur = next;
		}
		next = max(next, i + vect[i]);
		/* 
		打比方，当前jump = 2, cur = 8, i = 7, length = 8，next = 13其实已经不需要再跳了,这样next >= length就认为可以加1就不对了
		if(next >= vect.size())
		{
			return jump+1;
		}*/
	}
	return jump;
}


int main()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	v.push_back(1);
	v.push_back(4);
	cout << jump(v) << endl;
}
