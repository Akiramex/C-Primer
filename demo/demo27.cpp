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
    cout << "局部变量" << endl;
    X x;
    cout << endl;

    cout << "非引用参数传递" << endl;
    f1(x);
    cout << endl;

    cout << "引用参数传递" << endl;
    f2(x);
    cout << endl;

    cout << "动态分配" << endl;
    X* px = new X;
    cout << endl;

    cout << "添加到容器中" << endl;
    vector<X> vx;
    vx.push_back(x);
    cout << endl;

    cout << "释放动态分配对象" << endl;
    delete px;
    cout << endl;

    cout << "间接初始化和赋值" << endl;
    X y = x;
    y = x;
    cout << endl;  
}