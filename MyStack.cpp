#include "MyStack.h"
using namespace gtq;

void MyStack::check_n_alloc(){
   if(isempty()) reallocate();
}

void MyStack::reallocate(){
    size_t new_max = max? 2 * max: max;   //新的栈大小
    char* NewStackBegin = alloc.allocate(new_max);//NewStackBegin指向构造的位置
    auto tepBase = NewStackBegin;
    for(size_t i = 0; i != max; i++){
        alloc.construct(NewStackBegin++, std::move(*base++));
    }
    free();
    top = NewStackBegin;
    base = tepBase;
    max = new_max;
}

void MyStack::free(){
    if(base != nullptr){
        for(auto p = top; p != base; p--){
            alloc.destroy(p);
        }
        alloc.deallocate(base, max);
    }
}

bool MyStack::isempty(){
    if(top - base == max) 
        return true;
    return false; 
}

std::pair<char*, char*> MyStack::CopyStack(const char* a, const char* b){
    auto date = alloc.allocate(max);
    size_t i;
    //return{date, std::uninitialized_copy(a, b, date)};
    for(i = 0; i != max; ++i){
        alloc.construct(date + i, *(a + i));
    }
    return {date, date + i};
}

char MyStack::pop(){
    char s = *top;
    alloc.destroy(top);
    top--;
    return s;
}

void MyStack::push(const char &s){
    check_n_alloc();
    alloc.construct(++top, s);
}
//构造函数
MyStack::MyStack():top(nullptr),base(nullptr),max(0){
    reallocate();
}

MyStack::MyStack(const MyStack& s){
    max = s.max;
    auto newDate = CopyStack(s.top, s.base);
    top = newDate.second;
    base = newDate.first;
}

MyStack::~MyStack(){
    free();
    std::cout << "deconstructor\n";
}