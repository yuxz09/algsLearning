/*
一个int数组， 只有一种数出现奇数次，其他都出现偶数次
declare eor = 0; eor ^ each el in arr, then eor is the res

[2 1 3 1 3 1 3 2 1] => [1 1 1 1 2 2 3 3 3]

比方说a, b, c...
一个bit位是0还是1与a,b,c..这些数字的这个bit位相关。
如果这个bit位1的个数是偶数，根据类似无进位相加，所以该位置是0
如果这个bit位1的个数是奇数，根据类似无进位相加，所以该位置是1, 0同理
与顺序无关


一个int数组， 只有两种数出现奇数次，其他都出现偶数次
同理 整个数组异或一遍：eor = a ^ b
a(奇数次), b(奇数次), others(偶数次)
偶数others异或结果都是0
a之间异或结果是a, b之间异或结果是b
所以eor = a ^ b

然后再添加一个新的变量eor'
因为a和b是不同的，那么在某位上a,b其中一个是1另一个是0
则arr可以分出四类数字
X位上是1的：others(偶数次)， a(假设，奇数次)
X位上是0的：others(偶数次)， b(假设，奇数次)
用eor’去异或所有的arr中X位是1的，那么eor'得到的数字是a
因为others-1这个结果是0，所以出现奇数次的a，X位上是1无法消去
再用eor ^ eor' 那么得到的就是b



 */


#include <iostream>
using namespace std;

int main()
{
	int arr[10] = {1, 5, 2, 2, 2, 2, 4, 5, 6, 6};
	int eor = 0;
	int eor2 = 0;

	for(int i = 0; i < 10; i++)
	{
		//eor依次异或每个元素，结果存储后，结果再接着异或
		eor ^= arr[i];
	}
	//eor = a ^ b;
	//eor != 0
	//eor必然某一位是1

	int rightMostOne = eor & (~eor + 1); //提取出最右的1

	for(int i = 0; i < 10; i++)
	{
		if((arr[i] & rightMostOne) == 1) // or == 1
		{
			eor2 ^= arr[i];
		}
	}
	cout << eor2 << " " << (eor ^ eor2) << endl;
}

