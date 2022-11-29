#include "MyStack.h"

void printF(gtq::MyStack& rs){
    //for(size_t i = 0; i!= rs.top - rs.base + 1; ++i)//这里的top和i都在变化，不可以这么写
    while(rs.top - rs.base != 0)
        std::cout << rs.pop() << std::endl;
}

int main(){
    gtq::MyStack s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.push('e');
    printF(s);
    //s.~MyStack();
    std::cout << "-------------\n";
    return 0;
}