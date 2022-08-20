/**
 * @file demo13.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Screen
{
    friend class Window_mgr;
public:
    using pos = string::size_type;
    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd),contents(ht * wd,' ') {}
    Screen(pos ht, pos wd, char c) : height(ht),width(wd), contents(ht * wd, c) {}

    char get() const                        //返回光标处的字符
    { return contents[cursor]; }            //隐式内联

    inline char get(pos ht, pos wd) const;  //显式内联
    Screen &move(pos r, pos c);             //能在之后设成内联

    Screen &set(char);                      //设置光标所在位置的字符
    Screen &set(pos, pos, char);            //设置任意一位置所在的字符

    Screen &display(ostream &os)            //打印窗口内容
    { do_display(os); return *this; }
    const Screen &display(ostream &os) const// const重载版本
    { do_display(os); return *this; }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    void do_display(ostream &os) const { os << contents; };
};

inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this; 
}

char Screen::get(pos ht, pos wd) const
{
    pos row = ht *width;
    return contents[row + wd];
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col ,char ch)
{
    contents[r*width + col] = ch;
    return *this;
}
//---------------------------------------------------------------------------
class Window_mgr 
{
public:
    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex);
    ScreenIndex addScreen(const Screen&);   //向显示器添加一个屏幕
private:
    //默认情况下，一个window_mgr包含一个标准尺寸的空白 Screen
    vector<Screen> screens {Screen(24,80,' ')};
};

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen& s)
{
    screens.push_back(s);
    return screens.size() - 1;
}