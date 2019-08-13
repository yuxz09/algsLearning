/*
给定一个有序数组arr,和一个整数aim,请不重复打印arr中所有累加和为aim的二元组
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
    int indexL = 0;
    int indexR = vect.size()-1;


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
}



