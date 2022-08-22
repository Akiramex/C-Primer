/**
 * @file demo17.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-08-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<vector>
using namespace std;

bool Mysearch(vector<int>::iterator begin, vector<int>::iterator end, int target)
{
    while (begin != end && (*begin) != target)
        ++begin;
    if (begin != end)
        return true;
    else
        return false;
}

vector<int>::iterator Mysearch1(vector<int>::iterator begin, vector<int>::iterator end, int target)
{
    while (begin != end && (*begin) != target)
        ++begin;
    if (begin != end)
        return begin;
    else 
        return end;
}

string format(const string &s) { return s; }