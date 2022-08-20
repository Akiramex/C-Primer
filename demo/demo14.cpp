/**
 * @file demo14.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-08-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
using namespace std;

// 构造函数前 加入 explicit 可以抑制构造函数的隐式转换


//聚合类
//当一个类满足如下条件时：
// 1、所有成员都是 public
// 2、没有任何构造函数
// 3、没有类内初始值
// 4、没有父类，也没有virtual函数
struct Data {
    int val;
    string s;
};
//聚合类有特殊的初始化语句
Data val = {0, "Anna"};


//字面值常量类
class Debug
{
public:
    constexpr Debug(bool b = false) : hw(b), io(b), other(b) {}
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
    constexpr bool any() { return hw || io || other; }
    void set_io(bool b) { io = b; }
    void set_hw(bool b) { hw = b; }
    void set_other(bool b) { other = b; }
private:
    bool hw;
    bool io;
    bool other;
};