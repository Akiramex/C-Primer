/**
 * @file demo19.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-08-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<algorithm>
#include<numeric>
#include<string>
#include<vector>
#include<list>
#include<iterator>
using namespace std;

void func1()
{
    vector<int> vi = {1,2,3,4,1,1,2,6,7,3};
    int times = count(vi.begin(), vi.end(), 1);
    cout << times << endl;

    list<string> vs = {"h","e","l","l","o","w","o","r","l","d"};
    times = count(vs.begin(), vs.end(), "l");
    cout << times << endl;
}

void func2()
{
    //accumulate 求范围之和 <numeric>
    vector<int> vi = {1,2,3,4,1,1,2,6,7,3};
    int sum = accumulate(vi.cbegin(), vi.cend(), 0);
    
}

void func3()
{
    vector<int> vi = {1,2,3,4,1,1,2,6,7,3};
    fill_n(vi.begin(), vi.size(), 0);          //将vi的值都设置为 0
}

inline void myPrint(vector<string> &v)
{
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it <<" ";
    cout << endl;
}
void elimDups(vector<string>& vstr)
{
    //vector<string> vstr = {"i", "want", "to", "go", "to", "the", "countryside", "what", "about", "you"};
    myPrint(vstr);

    sort(vstr.begin(), vstr.end());                     //排序
    myPrint(vstr);

    auto end_uni = unique(vstr.begin(), vstr.end());    //消除重复元素
    myPrint(vstr);

    vstr.erase(end_uni, vstr.end());
    myPrint(vstr);

}
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

void func4()
{
    vector<string> vstr = {"i", "want", "to", "go", "to", "the", "countryside", "what", "about", "you"};
    elimDups(vstr);                                     //按字典排序，并删除重复元素

    //stable_sort:不改变相同元素的顺序（这里的相同元素指长度相等，与传入的谓词有关）
    //按长度重新排序，长度相同的单词维持字典序
    stable_sort(vstr.begin(), vstr.end(), isShorter);   //传入 isShorter谓词，按长度排序
    myPrint(vstr);
}

bool bigger_3(const string &s)
{
    return s.size() > 3; 
}
void func5()
{
    vector<string> vstr = {"i", "want", "to", "go", "to", "the", "countryside", "what", "about", "you"};
    myPrint(vstr);

    auto iter1 = partition(vstr.begin(), vstr.end(), bigger_3);     //partiton函数：根据谓词将 符合条件的放在左边，不符合条件的放在右边，返回最后一个符合条件元素后的迭代器
    myPrint(vstr);

    for (auto it = vstr.begin(); it != iter1; ++it)
        cout << *it << " ";
    cout << endl;
}

void biggers(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);    // 删除重复元素，并按字典排序

    // 按长度排序，长度相同维持字典顺序
    stable_sort(words.begin(), words.end(), 
    [](const string &s1, const string &s2)
    { return s1.size() < s2.size(); });
    
    // 获取一个迭代器，指向第一个满足 size() >= sz的元素
    // fine_if 返回第一个符合元素后的迭代器
    // auto wc = find_if(words.begin(), words.end(),
    //                 [sz](const string &a){ return a.size() >= sz; });

    // 打印长度大于等于给定值的单词，每个单词后面接一个空格
    // for_each(wc, words.end(),
    //         [](const string &s){ cout << s << " ";});

    // 也可以用 partition
    auto wc2 = stable_partition(words.begin(), words.end(),
                        [sz](const string &s){ return s.size() >= sz; });
    for_each(words.begin(), wc2,
            [](const string &s){ cout << s << " ";});

    cout << endl;
}

void func6()
{
    vector<int> vi = {1,1,2,3,4,4,5,6,7,7,7,8,9};
    list<int> li;
    // 调用插入迭代器 back_inserter  <iterator>
    unique_copy(vi.cbegin(), vi.cend(), back_inserter(li));
    
    for (auto a :li)
        cout << a << " ";
    cout << endl;
}

void func7()
{
    vector<int> vi = {1,2,3,4,5,6,7,8,9};
    list<int> l1, l2, l3;
    copy(vi.begin(), vi.end(), back_inserter(l1));
    copy(vi.begin(), vi.end(), front_inserter(l2));
    copy(vi.begin(), vi.end(), inserter(l3, l3.begin()));
    for (auto a :l1)
        cout << a << " ";
    cout << endl;
    for (auto a :l2)
        cout << a << " ";
    cout << endl;
    for (auto a :l3)
        cout << a << " ";
    cout << endl;
}
int main()
{
    // vector<string> vstr = {"i", "want", "to", "go", "to", "the", "countryside", "what", "about", "you"};
    // biggers(vstr, 4);

    func7();
    return 0;
}