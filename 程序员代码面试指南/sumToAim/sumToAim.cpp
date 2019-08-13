/*
给定一个有序数组arr,和一个整数aim,请不重复打印arr中所有累加和为aim的二元组
给定一个有序数组arr,和一个整数aim,请不重复打印arr中所有累加和为aim的三元组
 */


#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vect;
    vect.push_back(0);
    vect.push_back(0);
    vect.push_back(0);
    vect.push_back(0);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(2);
    vect.push_back(2);
    vect.push_back(6);
    vect.push_back(6);
    vect.push_back(7);
    vect.push_back(7);
    vect.push_back(7);
    vect.push_back(7);
    vect.push_back(8);
    vect.push_back(8);
    vect.push_back(8);
    vect.push_back(9);
    vect.push_back(9);
    vect.push_back(10);


    int aim = 8;//0-8  1-7  2-6
    int indexStart = 0;
    int indexL = indexStart + 1;
    int indexR = indexStart;
    //三元组
/*
    while(indexStart <= vect.size()-3)
    {
        for(indexL = indexStart+1, indexR = vect.size()-1; indexL < indexR; indexL++, indexR--)
        {
            if(vect[indexL] + vect[indexR] < aim - vect[indexStart])
            {
                indexL++;
            }
            else if(vect[indexL] + vect[indexR] > aim - vect[indexStart])
            {
                indexR--;
            }
            else
            {
                if(indexStart == 0 || vect[indexL] != vect[indexL-1])//indexStart  <==> indexL==indexStart表示一开始进来就可以打印的，三元组每一组允许有重复数字，但是三元组之间不能重复
                {
                    cout << vect[indexStart] << " " << vect[indexL] << " " << vect[indexR] << endl;
                }
                indexL++;
                indexR--;
            }
        }
        indexStart++;
    }
*/
    //二元组
/*
    while(indexL < indexR)
    {
        if(vect[indexL] + vect[indexR] < aim)
        {
            indexL++;
        }
        else if(vect[indexL] + vect[indexR] > aim)
        {
            indexR--;
        }
        else
        {
            if(indexL == 0 || vect[indexL-1] != vect[indexL])//vect[indexR+1] != vect[indexR]也可以
            {
                cout << vect[indexL] << " " << vect[indexR] << endl;
            }
            indexL++;
            indexR--;
        }
    }
*/
}



