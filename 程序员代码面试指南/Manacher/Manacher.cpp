//求字符串中最长回文子串长度

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//string to manacher string
//make string str be an odd length string
//length: n,每一个字符前加'#', n个'#',最后再加一个'#'，所以char array一共2n+1个字符
char* ManacherStr(string s, int n)
{
	char* arr = new char[n];

	int index = 0;
	for(int i = 0; i < n; i++)
	{
		if(i % 2 == 0)//每一个index为偶数的arr上都必须是#，奇数位置是s[index]
		{
			arr[i] = '#';
			//这里未必是特殊符号，也可以是string s里面的字符，可以保证实轴永远跟实轴比对，虚轴永远跟虚轴比对
			//#1#2#3#4, 假设是2往左右两边比对，#2#,#与#, 1#2#3， 1与3比对
		}
		else
		{
			arr[i] = s[index];
			index++;
		}
	}
	return arr;

}

int Manacher(char* arr, int sz)
{
	//最大回文半径:从当前下标i开始往左右任何一侧数，包括自身
//	int n = s.length()*2+1;	
	//最大回文半径数组
	int pArr[1000000] = {0};

	int maxn = 0;

	//r: 回文最右边界R的下一个坐标
	//#1#2#2#1#   -manacherstr
	//012345678   -index
	//022488888   -最长回文半径到达的位置R
	//133599999   -r
	int r = -1;

	//回文中心的位置
	//当回文半径R取到最后一个字符的index,那么c终止, c=当前下标
	//#1#2#2#1#   -manacherstr
	//012345678   -index
	//022488888   -最长回文半径到达的位置R = r-1
	//c = 4
	int c = -1;

	//只要从左到右计算出每个位置最大回文半径的值pArr，最大的值就是最大的回文半径
		
	/*	
	情况二、三、四: i在L...R之内, 根据c的定义，回文中心所以，L...R关于c位置对称
	L.......c.....i...R   -注意，i在L...R内，必然存在左边这样的结构
	[.......c.....i...]
	计算到i位置时，所有i之前的回文半径已经算过，找到i关于c位置对称的i'位置
	首先确定的是，pArr[c]是当前最大回文半径, pArr[c]必定大于pArr[i']
	*/

	//那么又出现三种情况

	/*	
	情况二：从c位置出发的最大回文半径pArr[c]可以完全包括i'位置出发的最大回文半径pArr[i']
	例如:
	{azytb[cdedc]kghshgk[cdedc]btyza}
	{LzytX[..i..]Y..c..K[..i..]MtyzR}, 第一个是i'，为了对齐
	X:i'的最长回文半径范围前的第一个字符
	Y:i'的最长回文半径范围后的第一个字符
	K:Y关于c位置对称的位置
	M:X关于c位置对称的位置

	首先 因为[..i'..]与[..i..]关于c位置对称,所以两者必定互为逆序
	.....arty..c..ytra.....

	其次 因为[..i'..]是回文串，所以[..i..]也一定是回文串
	....abcba...c...abcba
	那么以i位置的最大回文半径至少与i'位置pArr[i']是相等的

	再看 因为[..i'..]回文串只是这一段，说明X!=Y
	又因为关于c对称，所以 Y==K && X==M, 所以 M!= K

	综上所述，情况二中的关于i位置的最大回文半径pArr[i] = pArr[i']
	*/

	/*
	情况三:从c位置出发的最大回文半径pArr[c]可以无法包括i'位置出发的最大回文半径pArr[i']
	例如:
	[ab{cgdedgcba]kstskabcgdedgc}Mytk
	[.X{L..i..LY.]..c...KR..i..R}Mytk 
	找到当前i'位置，i'与i关于c位置对称
	找到L位置，即当前关于i'对称的L
	找到R位置，即当前关于i对称的R

	首先 {L..i..L  与  R..i..R}一定关于当前最长回文中心c对称，两段互为逆序
	其次 [..{L..i..L..]是关于i'的回文串，所以L..i..L也是回文串
		所以 R..i..R 也是回文串，也就是i'位置上的最长回文半径至少是 R..i..R

	X: L前面的一个字符
	Y: L后面的一个字符
	K: R前面的一个字符
	M: R后面的一个字符

	再看 [.X{L..i..LY.]是关于i'的回文串，所以  X==Y
	第一个R与第二个L对称，所以 K == Y
	又因为 X{L..i..LY.]..c...KR..i..R}M 中 X != M, 所以 K!=M

	综上所述，情况三的关于i位置的最大回文半径pArr[i]即i..R这一段
	*/


	/*
	情况四：i'位置的最大回文半径最左边刚好与pArr[c]的最大回文半径最左边相等
	例如：
	{abcdcbakskabcdcba}kyt
	{L..i....c....i..R}kyt
	[...i..].c.[..i...]kyt

	[...i...]c[...i...]关于c位置对称，所以两段互为逆序
	又因为[...i'...]关于i'对称，所以[...i...]关于i对称
	但是可能i位置可以扩的更大
	 */
	
	int res = 0;
	for(int i = 0; i < sz; i++)
	{
		//[L...R]r
		if(i < r)// i在[L...R]之间
		{
			//包括情况二，i'回文半径在L...R之间,pArr[2*c-i]
			//包括情况三，i'回文半径在L...R之外, r- i
			//包括情况四，压线
			pArr[i] = min(pArr[2*c-i], r - i);
		}
		else//// i在[L...R]之外
		{
			//包括情况一，i在r之外，i位置还可以再扩，所以至少包含它自己
			pArr[i] = 1;
		}
		while(i+pArr[i] < sz && i-pArr[i] >= 0)
		{
			if(arr[i+pArr[i]] == arr[i-pArr[i]])
			{
				pArr[i]++;
			}
			else
			{
				break;
			}
		}
		//如果i位置可以获得更大的回文半径，那么更新数值r
		if(i+pArr[i] > r)
		{
			r = pArr[i]+i;
			c = i;//不断记录最大回文半径的下标
		}
		//不断刷新最大回文半径
		maxn = max(maxn, pArr[i]);	
	}
	return maxn-1;
}


int main()
{
	string s = "abcdedckskcdedcba";	
	cout << s.length() << endl;
	int sz = s.length()*2+1;
	char* res = ManacherStr(s, sz);
	int l = Manacher(res, sz);
	cout << l << endl;
	
}

/*

测试string是否转换成manacher string
	int n = s.length()*2+1;
	for(int i = 0; i < n; i++)
	{
		cout << res[i];
		//or 
		//cout << *(res+i);
	}
*/



