/**
 * @file demo23.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-08-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<vector>
using namespace std;

vector<int> *new_vector()
{
    return new (nothrow) vector<int>;
}
void read_ints(vector<int> *p)
{   
    int i;
    while (cin >> i)
        p->push_back(i);
}
void print_ints(vector<int> *p)
{
    for (auto it = p->cbegin(); it != p->cend(); it++)
        cout << *it <<" ";
    cout << endl;
}

int main()
{
    vector<int> *pv = new_vector();
    if (!pv)
    {
        cout << "memory is not enough" << endl;
        return -1;
    }

    read_ints(pv);
    print_ints(pv);

    delete pv;
    pv = nullptr;

    return 0;
}