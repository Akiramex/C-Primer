/**
 * @file demo09.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
using namespace std;

//返回数组指针
//法1：类型别名
typedef int arrT[10];   //arrT是一个类型别名，他表示的类型是含有10个整数的数组
using arrT = int[10];   //arrT的等价声明
arrT* func(int i);      //func返回一个指向含有10个整数的数组的指针

//法2：直接声明
int (*func1(int i))[10];    

//法3：尾置返回类型
auto func2(int i)->int (*)[10]; 

//法4：使用decltype
int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};
decltype(odd) *func3(int i)
{
    return (i % 2)? &odd : &even;   //返回一个指向数组的指针
}

//-----------------------------------------------------------------------------------------------------
string (&function1())[10];

using arrS = string[10];
arrS& function2();

auto function3()->string(&)[10];

string str[2];
decltype(str) &function4();