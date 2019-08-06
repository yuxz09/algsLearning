#include <iostream>
using namespace std;

//时间复杂度 O(M) M为str长度
int* getNext(string str)
{
	static int next[1000000] = {0};////

	//强行规定
	next[0] = -1;//////
	next[1] = 0;/////

	int i = 2;
	int cn = 0;

	while(i < str.length())
	{
		if(str[i-1] == str[cn])
		{
			//cn为i-1位置上的最长前缀长度的后一个位置
			//因为相等，所以cn作为最长前缀长度的后一个位置需要延长
			next[i] = cn + 1;/////
			cn = cn + 1;////
			i++;////
		}
		else if(cn == 0)
		{
			next[i] = 0;
			i++;///
		}
		else
		{
			cn = next[cn];//
		}
	}
	return next;
}


int kmp(string str1, string str2)
{
	int *next = getNext(str2);
	if(str1.length() < str2.length())
	{
		return false;
	}
	int i = 0;
	int j = 0;
	for(i = 0, j = 0; i < str1.length() && j < str2.length(); )
	{
		if(str1[i] == str2[j])
		{
			i++;
			j++;
		}
		else if(next[j] == -1)//str2的j位置没有前缀与后缀相等的情况 或者说 j == 0
		{
			i++;
		}
		else
		{
			j = next[j];
		}
	}
	if(j == str2.length())
	{
		return i - j;
	}
	else
	{
		return -1;
	}
}

int main()
{
	string str1 = "aabsaatyaabsaakaabsaatyaabsaaabz";
	string str2 = "aabsaatyaabsaakaabsaabz";
//	string str = "ababaaaba";
	cout << kmp(str1, str2) << endl;

/*
	for(int i = 0; i < str.length(); i++)
	{
		cout << *(arr+i) << endl;
	}
*/
	return 0;
}
