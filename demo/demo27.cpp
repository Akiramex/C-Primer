/**
 * @file demo27.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-08-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<vector>
#include<iostream>
using namespace std;

struct X
{
    X() {cout << "X()" << endl;}
    X(const X&) {cout << "X(const X&)" << endl;}
    X& operator=(const X&) 
    {
        cout << "X& operator=(const X&)" << endl;
        return *this;
    }
    ~X() {cout << "~X()" << endl;}
};

void f1(X x)
{

}

void f2(X &x)
{

}

int main()
{
    cout << "�ֲ�����" << endl;
    X x;
    cout << endl;

    cout << "�����ò�������" << endl;
    f1(x);
    cout << endl;

    cout << "���ò�������" << endl;
    f2(x);
    cout << endl;

    cout << "��̬����" << endl;
    X* px = new X;
    cout << endl;

    cout << "��ӵ�������" << endl;
    vector<X> vx;
    vx.push_back(x);
    cout << endl;

    cout << "�ͷŶ�̬�������" << endl;
    delete px;
    cout << endl;

    cout << "��ӳ�ʼ���͸�ֵ" << endl;
    X y = x;
    y = x;
    cout << endl;  
}