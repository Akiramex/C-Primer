/**
 * @file demo30.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-09-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<string>
#include<set>

using namespace std;

class Folder;
class Message
{
public:
friend void swap(Message &lhs, Message &rhs);
    // folders被隐式初始为空集合
    explicit Message(const string &str = "") : contents(str) {}
    Message(const Message &m) : contents(m.contents), folders(m.folders)    // 拷贝构造函数
    {
        add_to_Folders(m);
    }
    Message& operator=(const Message &rhs)  // 拷贝赋值运算符
    {
        remove_from_Folders();
        contents = rhs.contents;
        folders = rhs.folders;
        add_to_Folders(rhs);
        return *this;
    }
    ~Message()                           // 析构函数
    {
        remove_from_Folders();
    }
    // 从给定 Folder集合中添加/删除本 Message
    void save(Folder&);
    void remove(Folder&);
    void addFldr(Folder *f) { folders.insert(f);}
    void remFldr(Folder *f) { folders.erase(f); }
private:
    string contents;            // 实际消息文本
    set<Folder*> folders;       // 包含本 Message 的 Folder

    // 工具类
    // 将本 Message添加到指向参数的 Folder中
    void add_to_Folders(const Message &m)
    {
        for (auto f : m.folders)
        {
            f->addMsg(this);
        }
    }
    // 从 folders中的每个 Folder中删除本 Message
    void remove_from_Folders()
    {
        for (auto f : folders)
        {
            f->remMsg(this);
        }
    }
    

};
void Message::save(Folder &f)
{
    folders.insert(&f);         // 将给定 Folder添加到我们的 Folder列表中
    f.addMsg(this);             // 将本 Message添加到 f的 Message集合中
}
void Message::remove(Folder &f)
{
    folders.erase(&f);          // 将给定 Folder从我们的 Folder列表中删除
    f.remMsg(this);             // 将本 Message从 f的 Message集合中移除
}
void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    // 将每个消息的指针从它原来所在 Folder中删除
    for (auto f : lhs.folders)
    {
        f->remMsg(&lhs);
    }
    for (auto f : rhs.folders)
    {
        f->remMsg(&rhs);
    }
    // 交换 contents和 Folder指针 set
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);
    // 将每个 Message的指针添加到它的新 Folder中
    for (auto f : lhs.folders)
    {
        f->addMsg(&lhs);
    }
    for (auto f : rhs.folders)
    {
        f->addMsg(&rhs);
    }
}

class Folder
{
public:
    Folder(const Folder &f) : msgs(f.msgs)
    {
        add_to_Messages(f);
    }
    ~Folder()
    {
        remove_from_Msgs();
    }
    Folder& operator=(const Folder &f)
    {
        remove_from_Msgs();
        msgs = f.msgs;
        add_to_Messages(f);
        return *this;
    }
    void addMsg(Message* m) { msgs.insert(m);}
    void remMsg(Message* m) { msgs.erase(m); }

private:
    set<Message*> msgs;

    void add_to_Messages(const Folder &f)
    {
        for (auto msg : f.msgs)
        {
            msg->addFldr(this);
        }
    }
    void remove_from_Msgs()
    {
        while (!msgs.empty())
        {
            (*msgs.begin())->remove(*this);
        }
    }
};