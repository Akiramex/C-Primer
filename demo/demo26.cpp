/**
 * @file demo26.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-08-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<string>
#include<memory>
using namespace std;

int main()
{
    allocator<string> alloc;
    // 分配 100个未初始化的 String
    auto const p = alloc.allocate(100);
    string s;
    string *q = p;                      // q指向第一个string
    while (cin >> s && q != p + 100)
    {
        alloc.construct(q++, s);        // 用 s初始化 *q
    }
    const size_t size = q - p;          // 记录读取了多少个 string

    //使用数组
    for (size_t i = 0; i < size; ++i)
        cout << p[i] << " ";
    cout<<endl;

    while (q != p)
        alloc.destroy(--q);             // 调用析构函数
    alloc.deallocate(p, 100);           // 释放内存
    
    return 0; 
}
