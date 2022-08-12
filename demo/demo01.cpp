/**
 * @file demo1.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-07-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
int main()
{
    int sum = 0, val = 0;
    while (std::cin>>val)
    {
        sum += val;
    }
    std::cout<<sum<<std::endl;
    system("pause");
    return 0;
}