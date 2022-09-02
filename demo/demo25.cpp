/**
 * @file demo25.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-08-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
using namespace std;

void new_array()
{
    const char* c1 = "HELLO ";
    const char* c2 = "WORLD";

    char* r = new char[strlen(c1) + strlen(c2) + 1];
    strcpy(r, c1);
    strcat(r, c2);
    cout << r << endl;

    string s1 = "hello ";
    string s2 = "world";
    strcat(r, (s1+s2).c_str());
    cout << r << endl;

    delete[] r;
}
