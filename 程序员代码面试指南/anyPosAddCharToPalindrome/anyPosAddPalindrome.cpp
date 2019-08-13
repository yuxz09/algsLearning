/*
添加最少字符使字符串整体都是回文字符串
给定一个字符串 str,如果可以在 str 的任意位置添加字符,请返回在添加字符最少的情况 下,让 str 整体都是回文字符串的一种结果。

dp[i][j]:任何一个位置至少添加几个字符
i...j: i<=j
范围上尝试的都有这样的特征，对角线下不用管(i>j)
i==j:对角线上，都是添加0个字符
对角线旁边的一个，统一至多再添加1个字符

假设i==2，j==7
(1) [3...7]:dp[i+1][j]+1
(2) [2...6]:dp[i][j-1]+1
(3) [3...6]当且仅当str[2] == str[7]:dp[i+1][j-1]
return dp[0][length()-1];

    0123456789
  a12bc3d2f1
   0
   1
   2
   3
   4
   5
   6
   7
   8
   9
 */

#include <iostream>
#include <string>
using namespace std;

//先填对角线和对角线右边的一个
//所以每一行都是从对角线右边的第二个开始填
//第二个开始填需要dp[i+1][j]和dp[i][j-1]
//所以从dp[j-2][j]的位置向上填
int** anyPosAddPalindrome(string str)
{
    int **dp = new int*[str.length()];
    for (int i = 0; i < str.length(); i++)
    {
        dp[i] = new int[str.length()];
    }
    dp[0][0] = 0;
    for(int j = 1; j < str.length(); j++)
    {
        dp[j][j] = 0;
        dp[j-1][j] = str[j-1]==str[j] ? 0 : 1;
        for(int i = j-2; i >= 0; i--)//
        {
            if(str[i] == str[j])
            {
                dp[i][j] = dp[i+1][j-1];
            }
            else
            {
                dp[i][j] = min(dp[i+1][j], dp[i][j-1])+1;
            }
        }
    }
    return dp;
}

string getResChar(string str)
{
    int** addNum = anyPosAddPalindrome(str);
//    for(int i = 0; i < str.length(); i++)
//    {
//        for(int j = 0; j < str.length(); j++)
//        {
//            cout << addNum[i][j] << " ";
//        }
//        cout << "\n";
//    }
  //  cout << addNum[0][str.length()-1] << endl;
    char* res = new char[str.length() + addNum[0][str.length()-1]];
    int i = 0;
    int j = str.length()-1;
    int lres = 0;
    int rres = str.length() + addNum[0][str.length()-1]-1;////-1

    while(i <= j)
    {
        if(str[i] == str[j])
        {
            res[lres] = str[i];
            i++;
            lres++;
            res[rres] = str[j];
            rres--;
            j--;
        }
            //比如0....20这个位置的结果，通过  并且str[0] != str[20],所以不会是左下角
            //如果是右下角，一定会+1,所以一定是从左边过来的
            // 5  6(i==0,j==20)
            // 6  6
            //那么0....20的结果就是从0...19来的，并且是把str[20]的结果添加在最左边得到20..0...19..20
        else if(addNum[i][j-1] < addNum[i+1][j])
        {
            res[lres] = str[j];//填好补上的值
            res[rres] = str[j];
            lres++;
            j--;//第一次是i==0,j==20, 第二次是i==0,j==19，看0...19从哪里来
            rres--;
        }
        else//一定从右下角过来的, 1...20过来的，所以一定是把str[0]补到最右侧 0...1....20...0
        {
            res[rres] = str[i];
            rres--;
            res[lres] = str[i];
            lres++;
            i++;
        }
  //      for(int i = 0; i < str.length() + addNum[0][str.length()-1]; i++)
  //      {
  //          cout << res[i];
  //      }
  //      cout << "\n";
    }
    string str_res = "";
    for(int i = 0; i < str.length() + addNum[0][str.length()-1]; i++)
    {
        str_res += res[i];
    }
    return str_res;
}

int main()
{
//  string s1 = "ABA";
    //string s2 = "AB";
    string s3 = "AB1CD2EFG3H43IJK2L1MN";
    cout << getResChar(s3) << endl;

}
