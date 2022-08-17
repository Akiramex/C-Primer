/**
 * @file demo08.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-08-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
using namespace std;

//使用范围for语句遍历多维数组时，要将所有外层的循环设为 引用,因为如果不是引用类型，编译器初始化会把其变成指针，造成编译不通过

int main()
{
    int arr[10][10] = {0};  //第一个元素列表初始化为 0，其他元素默认初始化为 0
    for (auto &row : arr)
        for (auto col : row)
            cout << col << endl;
}