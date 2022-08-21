/**
 * @file demo15.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-08-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<fstream>
using namespace std;
istream& func1(istream &in)
{
    int val;
    while (in >> val, !in.eof())    // 直到遇到文件结束符才停止读取
    {
        if (in.bad())
            throw runtime_error("IO流错误");
        if (in.fail())
        {
            cerr << "数据错误，请重试：" << endl;
            in.clear();
            in.ignore(100, '\n');
            continue;
        }
        cout << val << endl;
    }
    in.clear();
    return in;
}

int main()
{
    cout << "请输入一些整数，按Ctrl+Z结束" << endl;
    func1(cin);
    return 0;

    //刷新输出缓冲区
    cout << "hi!" << endl;  // 输出 hi和一个换行,然后刷新缓冲区
    cout << "hi!" << flush; // 输出 hi，然后刷新缓冲区
    cout << "hi!" << ends;  // 输出 hi和一个空字符，然后刷新缓冲区
    fstream f;
    
}