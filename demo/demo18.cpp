/**
 * @file demo18.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-08-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<forward_list>
#include<fstream>
using namespace std;

//分奇数，偶数
void func1()
{
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    vector<int> vi;
    list<int> li;

    vi.assign(ia, ia + 11);     //将数据拷贝到 vector
    li.assign(ia, ia + 11);     //将数据拷贝到 list

    vector<int>::iterator vit = vi.begin();
    while (vit != vi.end())
        if (!(*vit & 1))    //偶数
            vit = vi.erase(vit);    // erase返回被删除元素的下一位置迭代器    
        else 
            ++vit;

    list<int>::iterator lit = li.begin();
    while (lit != li.end())
        if (*lit & 1)       //奇数
            lit = li.erase(lit);
        else 
            ++lit;

    for (auto a : vi)
        cout << a <<" ";
    cout<<endl;
    for (auto b : li)
        cout << b <<" ";
    cout << endl;
}

//forward_list容器的 特殊操作
void func2(forward_list<int> li)
{
    forward_list<int>::iterator curr = li.begin();          //当前节点
    forward_list<int>::iterator prev = li.before_begin();   //前驱节点
    while (curr != li.end())
        if (*curr & 1)      //奇数
            curr = li.erase_after(curr);
        else            
        {
            prev = curr;            //同步后移        
            ++curr;
        }
}

void func3(forward_list<string> ls, const string &str1, const string &str2)
{
    forward_list<string>::iterator curr = ls.begin();          //当前节点
    forward_list<string>::iterator prev = ls.before_begin();   //前驱节点

    bool flag = false;                      //是否找到  str1的标志位
    while (curr != ls.end() && !flag)
    {
        if(*curr == str1)                   //找到 str1，在后面插入 str2，并退出函数
        {
            ls.insert_after(curr, str2);    
            flag = true;
        }
        else
        {
            prev = curr;                    //同步后移
            ++curr;
        }
    }
    
    if(!flag)
        ls.insert_after(prev, str2);        //递归到末尾，未找到 str1，在链尾插入
}

void func4(string &s, const string &oldVal, const string &newVal)
{
    auto l = oldVal.size();
    if (!l)                         //如果 l为 0
        return;
    string::iterator iter = s.begin();
    while (iter != s.end())
    {
        auto iter1 = iter;
        auto iter2 = oldVal.begin();
        // s中 item开始的字串必须每个字符都于 oldVal相同
        while (iter2 != oldVal.end() && *iter1 == *iter2)
        {
            ++iter1;
            ++iter2;
        }
        if (iter2 == oldVal.end())  //字符串相等
        {
            iter = s.erase(iter, iter1);        //删除item到 item1这段字符
            if (newVal.size())                  //替换字串是否为空
            {
                iter2 = newVal.end();
                do 
                {
                    iter2--;
                    iter2 = s.insert(iter, *iter2);     //从后往前逐个插入 newVal的字符    
                } while (iter2 > newVal.begin());
            }
            iter += newVal.size();                      //迭代器移动到插入内容之后
        }
        else ++iter;
    }
}
void func4_2(string &s, const string &oldVal, const string &newVal)
{
    size_t p = 0;
    while ((p = s.find(oldVal, p)) != string::npos)     //找到相同字符串的第一个位置，赋值给 p，未找到则退出循环
    {
        s.replace(p, oldVal.size(), newVal);            //将找到的字符串替换为newVal的内容
        p += newVal.size();
    }
}


void func5(string &name, const string &prefix, const string &suffix)
{
    name.insert(name.begin(), 1, ' ');
    name.insert(name.begin(), prefix.begin(), prefix.end());
    name.append(" ");
    name.append(suffix.begin(), suffix.end());
}
void func5_2(string &name, const string &prefix, const string &suffix)
{
    name.insert(0, " ");
    name.insert(0, prefix);
    name.insert(name.size(), " ");
    name.insert(name.size(), suffix);
}

void func6()
{
    string s("ab2c3d7R4E6"), numbers("0123456789");
    string::size_type pos = 0;
    while ((pos = s.find_first_of(numbers, pos)) != string::npos)
    {
        cout << s[pos] <<" ";
        ++pos;
    }
    cout<<endl;
    pos = 0;
    while ((pos = s.find_first_not_of(numbers, pos)) != string::npos)
    {
        cout << s[pos] <<" ";
        ++pos;
    }
    cout<<endl;
}

void func7(const string &address)
{
    string word, longest_word;
    unsigned max_size = 0;
    ifstream file(address);
    if(!file)
    {
        cerr << "无法打开文件" << endl;
        return;
    }
    else
    {
        while (file >> word)            //逐个读取单词
        {
            if (word.find_first_of("bdfghjklpqty") != string::npos)
                continue;
            cout << word << " ";
            if (max_size < word.size())     //最长的单词
                {
                    max_size = word.size();
                    longest_word = word;
                }
        }
        cout << endl << longest_word << endl;
    }
}

void func8()
{
    vector<string> vs = {"123", "+456", "-789"};
    int sum = 0;

    for (auto iter = vs.begin(); iter != vs.end(); iter++)
    {
        sum += stoi(*iter);
    }

    cout << sum << endl;
}
int main()
{
    func8();
    return 0;
}