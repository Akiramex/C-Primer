/**
 * @file demo12.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
using namespace std;

class Person
{
friend istream &read (istream &is, Person &per);
friend ostream &print (ostream &os, const Person &per);
private:
    string strName;     //姓名
    string strAddress;  //地址
public:
    Person() = default;
    Person(string s1, string s2) :strName(s1), strAddress(s2) {};
    explicit Person(istream& is) { read(is,*this);};

    string getName() const { return strName;};
    string getAddress() const { return strAddress;};
};

istream &read (istream &is, Person &per)
{
    is >> per.strName >> per.strAddress;
    return is;
}

ostream &print (ostream &os, const Person &per)
{
    os << per.getName() << per.getAddress();
    return os;
}