/**
 * @file demo16.cpp
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
#include<ostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

void Myread(const string &address)
{
    ifstream in(address);
    if (!in)
    {
        cerr << "无法打开输入文件" << endl;
        return;
    }

    string line;
    vector<string> words;
    while (getline(in, line))
    {
        words.push_back(line);
    }

    in.close();

    auto it = words.begin();
    while (it != words.end())
    {
        cout << *it << endl;
        ++it;
    }
    return;
}

void Mywrite(const string &address)
{
    ofstream out(address, ostream::app);    //追加的方式打开
    if (!out)
    {
        cerr << "无法打开输入文件" << endl;
        return;
    }
    string line;
    while (getline(cin, line))  //整行输入，换行 Ctrl+Z 结束输入
    {
        out << line << endl;
    }
}

void p289_89(const string &address)
{
    ifstream in(address);
    if (!in)
    {
        cout << "文件打开失败" <<endl;
        return;
    }
    string line;
    vector<string> words;
    while (getline(in, line))
    {
        words.push_back(line);
    }

    in.close();

    auto it = words.begin();
    while (it != words.end())
    {
        istringstream line_str(*it);    //从 vector 读取数据
        string word;
        while (line_str >> word)    //从 istringstream流写入数据到 word
            cout << word << " ";
        cout << endl;
        ++it;
    }
}

int main()
{
    Mywrite(".\\demo16.txt");
    return 0;
}