#include <MyStack.h>

void printF(gtq::MyStack& rs){
    for(size_t i = 0; i!= rs.top - rs.base; ++i)
        std::cout << rs.pop() << std::endl;
}

int main(){
    gtq::MyStack s;
    s.push('a');
    s.push('b');
    s.~MyStack();
}