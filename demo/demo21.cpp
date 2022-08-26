/**
 * @file demo21.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-08-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<fstream>
#include<sstream>
#include<map>
#include<set>
#include<list>
#include<string>
#include<utility>
#include<vector>
using namespace std;

//统计一个文件中单词出现的次数
void func1(const string &address)
{
    ifstream file(address);
    map<string, size_t> word_count;
    set<string> exclude = {"A", "a", "An", "an", "and"};
    string word;
    while (file >> word)
        if(exclude.find(word) == exclude.end())             // 只统计不在exclude里面的单词
            ++word_count[word];
    for (const auto &w : word_count)
    {
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " time" : " times") << endl;
    }
}

//大写转小写，去除符号
string &trans(string &s)
{
    for (int p = 0; p < s.size(); ++p)
    {
        if (s[p] >= 'A' && s[p] <= 'Z')
            s[p] -= ('A' - 'a');
        else if (s[p] == ',' || s[p] == '.')
            s.erase(p, 1);  
    }
    return s;
}
void func2(const string& address)
{
    ifstream in_it(address);
    if (!in_it)
    {
        cerr << "打开文件错误" <<endl;
        return;
    }
    map<string, list<int>> word_lineno;
    string line;
    string word;
    int lineno;
    while (getline(in_it, line))            // 读取一行
    {
        ++lineno;
        istringstream l_in(line);           // 构造字符串流。 读取单词
        while (l_in >> word)
        {
            trans(word);
            word_lineno[word].push_back(lineno);    // 添加行号
        }
    }

    for (const auto &w : word_lineno)
    {
        cout << w.first << "所在行：";
        for (const auto &i : w.second)
            cout << i << " ";
        cout << endl;
    }
}

void func3(const string &address)
{
    ifstream in(address);
    if (!in)
    {
        cerr << "打开文件错误" <<endl;
        return;
    }
    vector<pair<string, int>> data;
    string s;
    int v;
    while (in >> s && in >> v)              // 读取一个字符串一个整数
        data.push_back(make_pair(s, v));

    for (const auto &d : data)
        cout << d.first << " " << d.second << endl;
}

void remove_author(multimap<string,string> &book, string &author)
{
    auto pos = book.equal_range(author);
    if (pos.first == pos.second)
        cout << author + " not exist" << endl;
    else
        book.erase(pos.first, pos.second);      // 删除该作者的所有著作
}

int main()
{
    func3("demo21.txt");
    return 0;
}