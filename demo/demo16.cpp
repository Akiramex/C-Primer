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
        cerr << "�޷��������ļ�" << endl;
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
    ofstream out(address, ostream::app);    //׷�ӵķ�ʽ��
    if (!out)
    {
        cerr << "�޷��������ļ�" << endl;
        return;
    }
    string line;
    while (getline(cin, line))  //�������룬���� Ctrl+Z ��������
    {
        out << line << endl;
    }
}

void p289_89(const string &address)
{
    ifstream in(address);
    if (!in)
    {
        cout << "�ļ���ʧ��" <<endl;
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
        istringstream line_str(*it);    //�� vector ��ȡ����
        string word;
        while (line_str >> word)    //�� istringstream��д�����ݵ� word
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