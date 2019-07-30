#include "randomPool.hpp"
#include <iostream>
using namespace std;

int main()
{
	RandomPool pool;
	pool.insertkey("key1");
	pool.insertkey("key2");
	pool.insertkey("key2");
	pool.insertkey("key1");
	pool.insertkey("key3");
	pool.insertkey("key4");
	pool.delkey("key2");
	for(auto it = pool.keyIndexMap.begin();  it!= pool.keyIndexMap.end(); it++)
	{
		cout << it -> first << " " << it -> second << endl;
	}
	pool.delkey("key3");
	cout << pool.getRandom() << endl;
	cout << pool.getRandom() << endl;
	cout << pool.getRandom() << endl;
	cout << pool.getRandom() << endl;
	cout << pool.getRandom() << endl;
	cout << pool.getRandom() << endl;
	cout << pool.getRandom() << endl;
	cout << pool.getRandom() << endl;
	cout << pool.getRandom() << endl;

	cout << "------------------------" << endl;

	for(auto it = pool.keyIndexMap.begin();  it!= pool.keyIndexMap.end(); it++)
	{
		cout << it -> first << " " << it -> second << endl;
	}
}
