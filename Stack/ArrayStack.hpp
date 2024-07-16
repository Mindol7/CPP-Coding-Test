#include <cstdio>
#include <cstdlib>

inline void error(const char * message){
    printf("%s\n", message);
    exit(1);
}

const int MAX_STACK_SIZE = 20;

class ArrayStack{
    private:
        int top;
        char data[MAX_STACK_SIZE];
    public:
        ArrayStack(){top = -1;}
        ~ArrayStack(){}
        bool isEmpty(){return top == -1;}
        bool isFull(){return top == MAX_STACK_SIZE - 1;}
        
        void push(char e){
            if(isFull()){
                error("OverFlow");
            }
            data[++top] = e;
        }

        char pop(){
            if(isEmpty()) error("UnderFlow");
            return data[top--];
        }

        char peek(){
            if(isEmpty()) error("No");
            return data[top];
        }

        void display(){
            printf("%d\n", top);
            printf("Stack Element Number : %2d", top+1);
            for(int i = 0; i<=top; ++i){
                data[i];
            }
            printf("\n");
        }
};