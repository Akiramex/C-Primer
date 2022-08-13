/**
 * @file demo03.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-08-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
using namespace std;
/*
    类型别名
    typedef int zhengshu;
    or
    using zhengshu = int;

*/
// C++11标准。允许将变量声明为 constexpr 类型以便由编译器来验证变量的值是否为一个常量表达式
// 声明为 constexpr 的变量一定是一个常量，而且必须用常量表达式初始化

//常量表达式：值不会改变且在编译过程就能得到计算结果的表达式
constexpr int size()
{
    return 10;
}
int main()
{
    const int a = 10; // a是常量表达式
    int b = 20; //b不是常量表达式

    constexpr int c = 20;   //是
    constexpr int d = size();   //当size()是constexpr函数时才正确
}

/*
    auto和 decltype
    auto a = b;     //根据 b的值推断 a的类型，并定义


    decltype(f()) sum = x;  //将f()函数的返回值类型 作为 sum的数据类型
    //如果decltype使用的表达式是一个变量，则decltype返回该变量的类型（包括顶层const和引用）
    decltype(x) a;  //将 x的数据类型 给 a

*/