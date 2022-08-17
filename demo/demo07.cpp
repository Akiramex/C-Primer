/**
 * @file demo07.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-08-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<vector>
#include<string>
#include<cctype>
using namespace std;
void fun1()
{
    vector<int> ivec{1,2,3,4,5,6};
    int sum = 0;
    decltype(ivec.size()) i;
    for (i = 0; i < ivec.size() - 1; i += 2)
    {
        sum = ivec[i] + ivec[i+1];
        cout << sum << endl;
    }
    if (i == ivec.size() - 1)
        cout << ivec[i] << endl;
}

void fun2()
{
    vector<int> ivec{1,2,3,4,5,6,7};
    int sum = 0;
    decltype(ivec.size()) i = 0, j = ivec.size() - 1;
    while (i <= j)
    {
        if (i == j)
            cout << ivec[i] << endl;
        else
        {
            sum = ivec[i] + ivec[j];
            cout << sum << endl;
        }
        i++; j--;
    }
}

int main()
{
    // string word;
    // vector<string> vstr;
    // while (cin >> word)
    //     vstr.push_back(word);
    // for (auto &a : vstr)
    // {
    //     for (auto &c : a)
    //         c = toupper(c);
    //     cout << a << endl;
    // }

    fun2();
}