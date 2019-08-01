#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct point
{
	int x;
	int y;
};

int gcd(int x, int y)
{
	if(y == 0)
	{
		return x;
	}
	else
	{
		return gcd(y, x%y);
	}
}

int maxPointsOneLine(vector<point> vect) 
{
	int res = 0;

	string tmpx;
	string tmpy;
	string slope;

	unordered_map<string, int> mp;
	if (vect.size() == 0)
	{
		return 0;
	}

	if(vect.size() == 2)
	{
		return 2;
	}
	//用hashmap来存放斜率, 共该斜率的点
	for(int i = 0; i < vect.size(); i++)
	{
        int gcdres = 0;
        int samepos = 1;
        int samex = 0;
        int samey = 0;
        int tempx = 0;
        int tempy = 0;
        int tempmax = 0;
        mp.clear();
		for(int j = i + 1; j < vect.size(); j++)
		{
			//same position
			if(vect[i].x == vect[j].x && vect[i].y == vect[j].y)
			{
				samepos++;
			}
			//相同x
			else if(vect[j].x == vect[i].x && vect[j].y != vect[i].y)
			{
				samex++;
			}
			else if(vect[j].x != vect[i].x && vect[j].y == vect[i].y)
			{
				samey++;
			}
			else
			{
				tempx = vect[j].x - vect[i].x;
				tempy = vect[j].y - vect[i].y;
				//斜率分子分母化为最简分数
				gcdres = gcd(tempx, tempy);
				tempx = tempx / gcdres;
				tempy = tempy / gcdres;

				tmpx = to_string(tempx);
				tmpy = to_string(tempy);
				slope = tmpy + "_" + tmpx;

				if(mp.find(slope) == mp.end())//not find this slope, add it
				{
					mp.insert(make_pair(slope, 1));
				}
				else
				{
					mp[slope]++;
				}
				tempmax = max(tempmax, mp[slope]);//不断收集当前该点出发，不同斜率下的最多点的数量
			}
		}
		res = max(res, max(tempmax, max(samex, samey))+ samepos);
	}
	return res;
	//斜率用最简分数的string表示
}

//return 4
int main()
{
	int arrx[7] = {0, 0, 1, 2, 3, 4, 5};
	int arry[7] = {0, 0, 2, 3, 6, 12, 25};

	vector<point> vect;
	point temppoint;
	for(int i = 0; i < 7; i++)
	{
		temppoint.x = arrx[i];
		temppoint.y = arry[i];
		vect.push_back(temppoint);
	}	
	cout << maxPointsOneLine(vect) << endl;
}
