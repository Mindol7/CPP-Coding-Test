#include "ArrayStack.hpp"
int main(){
    ArrayStack stack;

    stack.push(Student(2015, "Minhyuk", "Computer"));
    stack.push(Student(2025, "Minhyuk11", "Computer11"));
    stack.push(Student(2035, "Minhyuk22", "Computer22"));

    stack.display();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.display();

    return 0;
}