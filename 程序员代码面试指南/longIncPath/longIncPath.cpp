/*
给定一个整型矩阵nums,每个位置都可以走向左、右、上、下四个方向，找到其中最长的递增路径

例子：
nums = 
[
	[9,9,4],
	[6,6,8],
	[2,1,1]
]
输出：4，最长的递增路径：[1,2,6,9]

nums=
[
	[3,4,5]
	[3,2,6]
	[2,2,1]
]
输出：4，最长的递增路径：[3,4,5,6]

先搞尝试的方法，再搞动态规划的方法

记忆化搜索 

 */

#include <iostream>
#include <vector>
using namespace std;



//假设在matrix中，从i行，j列出发，能走出的最长递增路径，返回
int process(vector<vector<int> > matrix, int i, int j, int length, int** dp)
{
	if(i < 0 || i >= length || j < 0 || j >= matrix[0].size())
	{
		return -1;
	}
	if(dp[i][j] != 0)//一定该位置被调用过
	{
		return dp[i][j];
	}


	//从i,j出发最长递增路径起码是1
//	int res = 1;
	int next1 = 0;
	int next2 = 0;
	int next3 = 0;
	int next4 = 0;
	if(i - 1 >= 0 && matrix[i-1][j] > matrix[i][j])
	{
		next1 = process(matrix, i-1, j, length, dp);
	}
	if(i + 1 < matrix[0].size() && matrix[i+1][j] > matrix[i][j])
	{
		next2 = process(matrix, i+1, j, length, dp);
	}
	if(j - 1 >= 0 && matrix[i][j-1] > matrix[i][j])
	{
		next3 = process(matrix, i, j-1, length, dp);

	}
	if(j + 1 < matrix[0].size() && matrix[i][j+1] > matrix[i][j])
	{
		next4 = process(matrix, i, j+1, length, dp);
	}
	int res = 1 + max(max(next1, next2), max(next3, next4));
	dp[i][j] = res;

	return res;
}


int maxPath(vector<vector<int> > matrix, int length)
{
	int res = INT_MIN;

	int **dp = new int*[length];
	for(int i = 0; i < length; i++)
	{
		dp[i] = new int[matrix.size()];
	}



	for(int row = 0; row < length; row++)
	{
		for(int col = 0; col < matrix[0].size(); col++)
		{
			res = max(res, process(matrix, row, col, length, dp));
		}
	}
	return res;
}

int main()
{
	vector<vector<int> > v(3, vector<int>(3));
	v[0][0] = 9;
	v[0][1] = 9;
	v[0][2] = 4;
	v[1][0] = 6;
	v[1][1] = 6;
	v[1][2] = 8;
	v[2][0] = 2;
	v[2][1] = 1;
	v[2][2] = 1;

	cout << maxPath(v, 3) << endl;
}


