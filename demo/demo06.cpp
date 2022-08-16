/**
 * @file demo06.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-08-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<string>
#include<cctype>
#include<vector>
using namespace std;

int main()
{
    //输出 str的每一个字符
    string str("some string");
    for (auto c : str)
        cout << c << endl;

    //统计 str的标点符号
    string str("hello!!!");
    decltype(str.size()) punct_cnt = 0;
    for (auto c : str)
        if (ispunct(c))
            punct_cnt++;
    cout << punct_cnt << endl;

    //将 str字符串改为大写
    string str("hello!!!");
    for (auto &c : str)
        c = toupper(c);
    cout << str << endl;

    //将输入的数字转成十六进制
    const string hexdigits = "0123456789ABCDEF";    //可能的十六进制数字
    string result;  //用于保存十六进制的字符串
    string::size_type n;    //用于保存从输入流读取的数
    while (cin >> n)
        if (n < hexdigits.size())
            result += hexdigits[n];
    cout << result << endl;

}
