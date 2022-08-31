/**
 * @file demo24.cpp
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
#include<memory>
using namespace std;

shared_ptr<vector<int>> new_vector()
{
    return make_shared<vector<int>>();
}
void read_ints(shared_ptr<vector<int>> spv)
{
    int i;
    while (cin >> i)
        spv->push_back(i);
}
void print_ints(shared_ptr<vector<int>> spv)
{
    for (const auto &v : *spv)
        cout << v << " ";
    cout << endl;
}
int main()
{
    auto spv = new_vector();
    read_ints(spv);
    print_ints(spv);
    return 0;
}