/**
 * @file demo28.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-08-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
using namespace std;

class Employee
{
private:
    static unsigned sn;
    string name;
    unsigned mysn;
public:
    unsigned get_mysn() const{ return mysn; } 
    Employee():mysn(sn++){};
    Employee(const string &s) 
    {
        name = s;
        mysn = sn++;
    }
    Employee(const Employee &e)
    {
        name = e.name;
        mysn = sn++;
    }
    Employee& operator= (const Employee &e)
    {
        name = e.name;
        mysn = sn++;
        return *this;
    }
};
unsigned Employee::sn = 0;

void f1(Employee s) { cout << s.get_mysn() << endl; }
void f2(const Employee &s) { cout << s.get_mysn() << endl; }

int main()
{
    Employee a, b = a, c = b;
    f1(a);f1(b);f1(c);
    f2(a);f2(b);f2(c);
    return 0;
}