#include "calculator.h"
using namespace pjl;

float Calculator::calculate() {
    sta = MyStack();
}

void Calculator::CalculatorInput()
{
    std::cin.get(expression, 100);
}

float Calculator::process(){
    for(size_t i = 0; expression[i] != '\n'; i++){
        switch (expression[i])
        {
        case '+':
            
            break;

        case '-':
            break;

        case '*':
            break;

        case '/':
            break;

        default:
            sta.push(expression[i]);
            break;
        }
    }
}

void Calculator::Prior(const char &input, MyStack &sta_top, char *p)
{
    if (input == ')')
    {
        while (*sta_top.top != '(')
        {
            *p = sta_top.pop();
            p++;
        }
        sta_top.pop(0);
        return;
    }
    else if (input == '-' || input == '+')
    {
        while (*sta_top.top != '(' || *sta_top.top != '\n')
        {
            *p = sta_top.pop();
            p++;
        }
        sta.push(input);
        return;
    }
    else
    { //输入时*和/时
        while (*sta_top.top != '(' || *sta_top.top != '\n')
        {
            if (*sta_top.top == '+' || input == '-')
            {
                sta.push(input);
                return;
            }
            else
            {
                *p = sta_top.pop();
                p++;
            }
        }
    }
}

MyStack &Calculator::PostfixExpression()
{
    MyStack PostfixSta;
    char s[100]{};
    char *ptr_s = s;
    size_t i = 0;
    for (size_t i = 0; expression[i] != '\n'; i++)
    {
        if (operators.find(expression[i]) != operators.end())
        { //是运算符号
            PostfixSta.push(expression[i]);
        }
        else
        {
            Prior(expression[i], PostfixSta, ptr_s);
        }
    }
    return PostfixSta;
}