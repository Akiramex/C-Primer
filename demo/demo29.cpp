/**
 * @file demo29.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-09-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
using namespace std;

// 定义行为像值的指类
class HasPtr
{
friend void swap(HasPtr &lhs, HasPtr &rhs);
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &H) : ps(new string(*H.ps)), i(H.i) {}
    HasPtr& operator= (const HasPtr &H)
    {
        auto newp = new string(*H.ps);      // 拷贝底层string
        delete ps;                          // 释放旧内存
        ps = newp;
        i = H.i;
        return *this;
    }
    ~HasPtr()
    {
        delete ps;
    }
private:
    string* ps;
    int i;
};
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    cout << "交换" << *lhs.ps << "和" << *rhs.ps <<endl;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

// 定义行为像指针的类
class HasPtr_p
{
public:
    // 构造函数分配新的 string和新的计数器，将计数器为 1
    HasPtr_p(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) {}
    // 拷贝构造函数拷贝所有三个数据成员，并递增计数器
    HasPtr_p(const HasPtr_p &p) :ps(p.ps), i(p.i), use(p.use) { ++*use; }
    HasPtr_p &operator=(const HasPtr_p &rhs)
    {
        ++*rhs.use;         // 递增右侧运算对象的引用计数
        if (--*use == 0)    // 然后递减本对象的引用计数
        {                   // 如果没有其他对象
            delete ps;
            delete use;
        }
        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;
        return *this;
    }
    ~HasPtr_p()
    {
        if (--*use == 0)
        {
            delete ps;
            delete use;
        }
    }
private:
    string *ps;
    int i;
    size_t *use;    //用来记录有多少个对象共享 *ps的成员
};