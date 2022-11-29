#pragma once
#include"MyStack.h"
#include <iostream>
#include <set>
namespace pjl{
class Calculator{
private:
    MyStack sta;  //计算栈
    char expression[100]{};//本来想使用动态内存，之后可以再写
    //char* ptr_char;
    void CalculatorInput();
    float process();
    MyStack& PostfixExpression();//之前没有写前缀表达式，需要转化！！！
    void  FreeCalculatorInput();
    void Prior(const char&, MyStack&, char *);
    std::set<char> operators = {'+', '-', '*', '/','(', ')'};
public:
    float calculate();
    Calculator();
    void clear();
};
}