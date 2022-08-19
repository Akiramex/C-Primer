/**
 * @file demo11.cpp
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

//对象在调用类内函数时候，会把对象地址传递给函数的隐式形参 this
//定义在类内的函数是隐式的 inline函数
class Sales_data 
{
friend istream &read(istream &is, Sales_data &item);
friend ostream &print(ostream &os, const Sales_data &item);
friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
public:
    //Sales_data() = default; //默认构造函数
    explicit Sales_data(const string &s = "") : bookNo(s) {}; //构造函数初始值列表
    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p*n) {};
    explicit Sales_data(istream &);  //读入一条交易信息

    string isbn() const{return bookNo;};    //const表示将this指针定义为指向常量指针,常量成员函数不能改变调用它的对象的内容
    //this本身是个常量指针
    Sales_data& combine(const Sales_data&); //函数定义在类外
private:
    double avg_price() const;   

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data::Sales_data(istream &is)
{
    read(is,*this); //read的作用是从 is中读取一条交易记录然后存入 this对象中
}

inline double Sales_data::avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else 
        return 0;
}

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;   //把 rhs的成员加到 this对象的成员上
    revenue += rhs.revenue;
    return *this;   //返回 this(调用该函数的成员)
}

istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}