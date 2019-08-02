#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void print(vector<int>& nums)
{
	for(int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << "\n";
}

bool partition(vector<int> v)
{
	if(v.size < 7)
	{
		return false;
	}
//	vector<vector<int>> res;
//	vector<int> cur;
	vector<int> index;
	unordered_map<int, int> mp;
	int tmpsum = 0;
	int pos1 = 0;
	int pos2 = 0;
	int pos3 = 0;

	int checksum = 0;
	int total = v[0];//保留总和，为了最后一步,最后一步不使用for pos-end来求解是否最后一部分符合lsum
	//算出0 ~ i-1位置上的和
	for(int i = 1; i < v.size(); i++)
	{
		tmpsum += v[i-1];
		mp[tmpsum] = i;//这里只是位置
		total += v[i];///
	}
	//需要一个变量记住左边的sum
	int lsum = v[0];
	for(int i = 1; i < v.size(); i++)
	{
		pos1 = i;
		checksum = lsum * 2 + v[pos1];
		if(mp.find(checksum) != mp.end())
		{
			pos2 = mp[checksum];
			checksum += v[pos2] + lsum;
			if(mp.find(checksum) != mp.end())
			{
				pos3 = mp[checksum];
				if(checksum + v[pos3] + lsum == total)
				{
					index.push_back(pos1);
					index.push_back(pos2);
					index.push_back(pos3);
					print(index);
					return true;
				}
			}
		}
		lsum += v[i];
	}
	return false;



}


int main()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(4);
	v.push_back(1);
	v.push_back(4);
	v.push_back(9);
	v.push_back(5);
	v.push_back(10);
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);

	cout << partition(v) << endl;
}
