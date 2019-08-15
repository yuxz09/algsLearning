/*
给定两个有符号的32位整数a和b，返回a和b中较大的

2^n == 2048

正数，有符号整型，第一位是0
负数，有符号整型，第一位是1


c = a-b
if c >= 0, scA = 1
	return a;
else c < 0, scA = 0
	return b;

if else  ==> 互斥写法


 */
#include <iostream>
using namespace std;

//input n == 0 || n == 1
//flip(): if n == 0, return 1; if n == 1, return 0;
int flip(int n)
{
	return n^1;
}

//if n >= 0, reutrn 1;
//if n < 0, return 0;
int sign(int n)
{
	return flip( (n>>31) & 1);//n>>31：把n的符号位右移动到最低位
}


int getMax(int a, int b)
{
	int c = a-b;//结果可能溢出
	int scA = sign(c);
	int scB = flip(scA);
	return a*scA+b*scB;//当发现有互斥条件，互斥条件就可以变成概率累加，两边只能一个1一个0
}

int getMax2(int a, int b)
{
	int c = a - b;
	int sa = sign(a);
	int sb = sign(b);
	int sc = sign(c);

	int diffab = sa ^ sb;//a和b的符号不一样，为1； 符号一样，为0

	int sameab = flip(diffab);//a和b的符号一样，为1； 符号不一样，为0

	int returnA = diffab * sa + sameab * sc;
	//符号不一样且sa==1,a是非负，必然a > b, return a
	//符号一样，a-b非负，return a

	int returnB = flip(returnA);

	return a*returnA + b*returnB;//保证加号左右两侧互斥，构造加号左右两侧互斥条件
}




int main()
{
	int a = 5;
	int b = 12;

	cout << getMax(a, b) << endl;
	cout << getMax2(a, b) << endl;

	int c = 6;
	int d = 2;
	cout << getMax(c, d) << endl;
	cout << getMax2(c, d) << endl;

	int e = -1;
	int f = -5;
	cout << getMax(e, f) << endl;
	cout << getMax2(e, f) << endl;

	int m = -9;
	int n = -3;
	cout << getMax(m, n) << endl;
	cout << getMax2(m, n) << endl;



}



