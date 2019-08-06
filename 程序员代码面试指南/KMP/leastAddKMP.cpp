/*
给定一个字符串str,只能在str的后面添加字符,生成一个更长的字符串,更长的字符串需要 包含两个str,且两个str开始的位置不能一样。求最少添加多少个字符。
比如:
str = "123123",后面最少添加"123",变成"123123123", 其中包含两个str,且两个str开始的位置不一样。 所以返回3
*/

#include <iostream>
using namespace std;


int getNext(string str)
{
	int* next = new int[str.length()+1];//多出一个位置，因为要求整个字符串的最长前缀最长后缀，所以包括字符串最后一个字符
	next[0] = -1;
	next[1] = 0;

	int i = 2;
	int cn = 0;

	while(i <= str.length())
	{
		if(str[i-1] == str[cn])//计算当前i前一个位置上i-1的前后缀长度
		{
			cn++;
			next[i] = cn;
			i++;
		}
		else if(cn == 0)
		{
			next[i] = 0;
			i++;

		}
		else
		{
			cn = next[cn];
		}

	}
	return next[str.length()];
}

//返回需要添加多少个字符
int leastAddStrs(string str)
{
	int m = getNext(str);
	int n = str.length();


	return n-m;

}

int main()
{
	string str1 = "123123";
	cout << leastAddStrs(str1) << endl;
	string str2 = "123546892123";
	cout << leastAddStrs(str2) << endl;
}