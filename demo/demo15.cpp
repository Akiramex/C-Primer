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
    while (in >> val, !in.eof())    // ֱ�������ļ���������ֹͣ��ȡ
    {
        if (in.bad())
            throw runtime_error("IO������");
        if (in.fail())
        {
            cerr << "���ݴ��������ԣ�" << endl;
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
    cout << "������һЩ��������Ctrl+Z����" << endl;
    func1(cin);
    return 0;

    //ˢ�����������
    cout << "hi!" << endl;  // ��� hi��һ������,Ȼ��ˢ�»�����
    cout << "hi!" << flush; // ��� hi��Ȼ��ˢ�»�����
    cout << "hi!" << ends;  // ��� hi��һ�����ַ���Ȼ��ˢ�»�����
    fstream f;
    
}