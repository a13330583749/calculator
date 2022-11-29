#pragma once
#include <iostream>
#include <memory>
#include <utility>
namespace pjl{
class MyStack
{
private:
    size_t max;
    char   m_ele;
    bool isempty();
    void check_n_alloc();//检测栈的内存是否足够
    void reallocate();//获得更多内存并拷贝栈
    static std::allocator<char> alloc;//分配内存类
    std::pair<char*,char*> CopyStack(const char*, const char*);
    void free();
public:
    char*  top;
    char*  base;
    //MyStack(size_t)设置栈大小的构造函数就没有弄了，会在reallocate出现问题
    MyStack();
    MyStack(const MyStack&);//拷贝构造函数好像没什么用，但还是写了吧
    ~MyStack();
    char pop();
    void pop(int);
    void push(const char &);
};
}