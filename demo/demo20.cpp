/**
 * @file demo20.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-08-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<iterator>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<list>
using namespace std;

void func1(const string &address)
{
    ifstream file(address);

    istream_iterator<string> str_it(file), eof;         // 从 file文件流中读取字符串
    // while (str_it != eof)
        // vec.push_back(*str_it++);

    vector<string> vec(str_it, eof);                    // 传入两个迭代器初始化容器
    for_each(vec.begin(), vec.end(), [](const string &s){ cout << s << " "; } );
}

void func2()
{
    istream_iterator<int> int_it(cin), eof;         // 从标准输入流读取
    vector<int> vi(int_it, eof);
    sort(vi.begin(), vi.end());                     // 升序排序

    ostream_iterator<int> out_it(cout, " ");        // 输出到标准输出流, 每打印一个元素追加一个 " "
    copy(vi.begin(), vi.end(), out_it);             // 若要输出不重复元素，copy替换成 unique_copy
}

void func3(const string &file_in, const string &file_out1, const string &file_out2)
{
    ifstream in(file_in);
    istream_iterator<int> in_it(in), eof;
    vector<int> vi(in_it, eof);                     // 读取数据输入到一个容器中

    // 将输入的数据按奇偶分区
    auto it = partition(vi.begin(), vi.end(), [](int i)->bool{ return i & 1; });

    ofstream out1(file_out1), out2(file_out2);

    ostream_iterator<int> out_it1(out1," ");        // 奇数拷贝到文件 1
    copy(vi.begin(), it, out_it1);

    ostream_iterator<int> out_it2(out2,"\n");       // 偶数拷贝到文件 2
    copy(it, vi.end(), out_it2);
}

void func3_ans(const string &file_in, const string &file_out1, const string &file_out2)
{
    ifstream in(file_in);
    istream_iterator<int> in_it(in), eof;

    ofstream out1(file_out1), out2(file_out2);
    ostream_iterator<int> out_it1(out1," "), out_it2(out2,"\n");
    
    while (in_it != eof)
    {
        if (*in_it & 1)
            *out_it1++ = *in_it;
        else
            *out_it2++ = *in_it;
        ++in_it;
    }
}

void func4()
{
    list<int>li = {0,1,2,3,0,1,2,3};
    // 利用反向迭代器查找最后一个 0的位置
    auto last_zero = find(li.rbegin(), li.rend(), 0);
    // 将迭代器向链头方向推进一个位置
    // 转换为普通迭代器时，将回到最后一个 0的位置
    ++last_zero;
    int p = 1;
    // 用 base函数将 last_zero 转换为普通迭代器
    for (auto iter = li.begin(); iter != last_zero.base(); ++iter, ++p) ;   //空语句

    if (p >= li.size())
        cout << "容器中没有0" << endl;
    else cout << "最后一个0在第" << p << "个位置" << endl; 
}

void func5()
{
    vector<int> v10 = {0,1,2,3,4,5,6,7,8,9};
    list<int> li;
    copy(v10.begin()+2, v10.begin()+7, front_inserter(li));

    for (auto a : li)
        cout << a << " ";
    cout << endl;
}
int main()
{
    // func1("demo18.txt");
    // func2();
    // func3("demo20.txt", "outfile1.txt", "outfile2.txt");
    func5();
}