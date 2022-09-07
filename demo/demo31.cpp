/**
 * @file demo31.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-09-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>  
#include<string>
#include<memory>
#include<utility>
#include<initializer_list>
#include<algorithm>
using namespace std;

class StrVec
{
public:
    // allocator成员进行默认初始化
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec&);                  // 拷贝构造函数
    StrVec& operator=(const StrVec&);       // 赋值运算符
    StrVec(initializer_list<string>);
    ~StrVec();                              // 析构函数
    void push_back(const string&);          // 拷贝函数
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string *begin() const { return elements; }
    string *end() const { return first_free; }
    void reserve(size_t);
    void resize(size_t, string&);
    void resize(size_t);
private:
    static allocator<string> alloc;         // 分配元素
    string *elements;                       // 指向数组首元素的指针
    string *first_free;                     // 指向数组第一个空闲元素的指针
    string *cap;                            // 指向数组尾后位置的指针
    // 被添加元素的函数所使用
    void chk_n_alloc()
    { if (size() == capacity()) reallocate(); }
    //工具函数，被拷贝构造函数、赋值运算符和析构函数所使用
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();                            // 销毁元素并释放内存
    void reallocate();                      // 获得更多内存并拷贝已有元素
}; 
void StrVec::push_back(const string &s)
{
    chk_n_alloc();                          // 确保有空间容纳新元素
    // 在 first_free指向的元素中构造 s的副本
    alloc.construct(first_free++, s);
}
pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
    // 分配空间保存给定范围中的元素
    auto data = alloc.allocate(e - b);
    // 初始化并返回一个 pair, first为新空间的首指针，second为最后一个构造元素后的位置
    return {data, uninitialized_copy(b, e, data)};
}
void StrVec::free()
{
    // 不能传递给 deallocate一个空指针，如果 elements为 0，函数什么也不做
    if (elements)
    {   // 逆序销毁旧元素
        for (auto p = first_free; p != elements; /* 空 */)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
        //或者if内用
        //for_each(elements, first_free, [](string &s){ alloc.destroy(&s); });
    }
    
}
StrVec::~StrVec()
{
    free();
}
StrVec::StrVec(const StrVec &s)
{
    // 调用 alloc_n_copy分配空间以容纳与 s一样多的元素
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}
StrVec& StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}
void StrVec::reallocate()
{
    // 分配当前两倍大小的空间，如果还未分配则分配单个空间
    auto newcapacity = size() ? size() * 2 : 1;
    // 分配新内存
    auto newdata = alloc.allocate(newcapacity);
    // 将数据由旧内存移到新内存
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();                                 // 释放原来的空间
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}
void StrVec::reserve(size_t nc)
{
    if (nc > capacity())
    {
        auto newcapacity = nc;
        auto newdata = alloc.allocate(newcapacity);
        auto dest = newdata;
        auto elem = elements;
        for (size_t i = 0; i != size(); ++i)
            alloc.construct(dest++, std::move(*elem++));
        free();
        elements = newdata;
        first_free = dest;
        cap = elements + newcapacity; 
    }
}
inline void StrVec::resize(size_t ns)
{
    if (ns > size())
    {
        while (size() < ns)
            push_back("");
    }
    else if (ns < size())
    {
        while (size() > ns)
        {
            alloc.destroy(--first_free);
        }
    }
}
inline void StrVec::resize(size_t ns, string &s)
{
    if (ns > size())
    {
        while (size() < ns)
            push_back(s);
    }
    else if (ns < size())
    {
        while (size() > ns)
        {
            alloc.destroy(--first_free);
        }
    }
}
inline StrVec::StrVec(initializer_list<string> il)
{
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

int main()
{

}