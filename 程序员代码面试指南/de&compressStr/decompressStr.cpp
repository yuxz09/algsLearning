/*
已知某个字符串只含有小写字母,压缩之后的字符串str包含数字、大括号和小写字符。请 根据str还原出原始字符串并返回。
比如:
3{2{abc}} -> abcabcabcabcabcabc 3{a}2{bc} -> aaabcbc
3{a2{c}} -> accaccacc
 */

#include <iostream>
#include <string>
using namespace std;


struct data
{
    string tmpres;
    int pos;
    data(string s, int i)
    {
        tmpres = s;
        pos = i;
    }
};

string get_KStr(int times, string str)
{
    string res = "";
    for(int i = 0; i < times; i++)
    {
        res += str;
    }
    return res;
}

//abc13{k7{ac}}def
//F函数定义：从start位置出发，开始转化字符串，遇到"}"或者终止位置停止转化
//返回类型，转化出来的字符串以及处理到的位置
//"{"括号前必有数字，所以 if(str[index] == '{')分支中，k 一定不为0
data F(int index, string str)
{
    string res;
    int k = 0;
    while(index < str.length() && str[index] != '}')
    {
        if(str[index] == '{')
        {
            data tmp = F(index+1, str);//一定是遇到"}"后返回
    //        cout << tmp.tmpres << endl;
            res += get_KStr(k, tmp.tmpres);//
            k = 0;
            index = tmp.pos + 1;
        }
        else
        {
            if(isdigit(str[index]))
            {
                k = 10*k + str[index]-'0';
            }
            else if(str[index] >= 'a' && str[index] <= 'z')
            {
                res += str[index];
            }
            index++;
        }
    }
    return data(res, index);
}



string decompress(string str)
{
    return F(0, str).tmpres;
}


int main()
{
    string str1 = "3{2{abc}}";
 //   cout << decompress(str1) << endl;

    string str2 = "3{a}2{bc}";
 //   cout << decompress(str2) << endl;

    string str3 = "3{a2{c}}";
 //   cout << decompress(str3) << endl;

    string str4 = "abc13{k7{ac}}def";
    cout << decompress(str4) << endl;


}
