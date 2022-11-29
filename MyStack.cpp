#include "MyStack.h"
using namespace pjl;

std::allocator<char> MyStack::alloc;//分配内存类

void MyStack::check_n_alloc(){
   if(isempty()) reallocate();
}

void MyStack::reallocate(){
    size_t new_max = max? 2 * max : 1;   //新的栈大小
    char* NewStackBegin = alloc.allocate(new_max);//NewStackBegin指向构造的位置
    char* tepBase = NewStackBegin;
    for(size_t i = 0; i <= max; i++){   //既然栈底是\000，那还是需要判断i<=max
        alloc.construct(NewStackBegin++, std::move(*(base + i)));//这里已经move走了，所以就算释放了内存了的意思吗
    }
    free();
    top = --NewStackBegin;
    base = tepBase;
    max = new_max;
}

void MyStack::free(){
    if(base != nullptr){
        for(auto p = top; p - base != -1; p--){
            alloc.destroy(p);
        }
        alloc.deallocate(base, max);
    }
}

bool MyStack::isempty(){
    if(top - base < max) 
        return false;
    return true; 
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
    alloc.destroy(--top);
    //top--;
    return s;
}

void MyStack::pop(int){
    char s = *top;
    alloc.destroy(--top);
    //top--;
}

void MyStack::push(const char &s){
    check_n_alloc();
    alloc.construct(++top, s);
}
//构造函数
MyStack::MyStack():max(0){
    base = top = alloc.allocate(1);
    //reallocate();
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