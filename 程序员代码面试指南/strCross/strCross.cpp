#include <iostream>
#include <vector>
#include <string>
using namespace std;


//dp[i][j] aim字符串要么来自str1,要么来自str2
/*
dp[i-1][j], 所以查看aim的长度为i+j-1，代表aim[0...i+j-2]是否能被str1[0...i-2]和str2[0...j-1]交错组成;
如果

dp[i][j-1]
*/

int strmix(string str1, string str2, string aim)
{
	int n1 = str1.length();
	int n2 = str2.length();

	
	vector<vector<int> > dp(n1+1, vector<int>(n2+1));
	dp[0][0] = 1;//aim为空串时，可以被str1空串,str2空串交错组成

	//只调用str1的字符能否满足aim的全部
	for(int i = 1; i <= n1; i++)
	{
		if(str1[i-1] == aim[i-1])
		{
			dp[i][0] = 1;
		}
		else
		{
			dp[i][0] = 0;
		}
	}
	for(int i = 1; i <= n2; i++)
	{
		if(str2[i-1] == aim[i-1])
		{
			dp[0][i] = 1;
		}
		else
		{
			dp[0][i] = 0;
		}
	}
	for(int i = 1; i <= n1; i++)
	{
		for(int j = 1; j <= n2; j++)
		{
			if((dp[i-1][j] == true && aim[i+j-1] == str1[i-1]) || (dp[i][j-1] == true && aim[i+j-1] == str2[j-1]))
			{
				dp[i][j] = 1;
			}
		}
	}
	return dp[n1][n2];
}

int main()
{
	string str1 = "AB";
	string str2 = "12";

	string aim1 = "AB12";
	string aim2 = "A1B2";
	string aim3 = "1A2B";
	string aim4 = "1AB2";
	string aim5 = "A12B";

	string aim6 = "B12A";
	string aim7 = "12AB";//任何一个string里面的字符不可以顺序变动

	cout << strmix(str1, str2, aim7) << endl;
}
