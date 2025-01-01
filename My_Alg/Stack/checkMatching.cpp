#include "ArrayStack.hpp"

bool checkMatching(const char * filename){
    FILE * fp = fopen(filename, "r");
    if(fp == NULL){
        error("There is no File\n");
    }

    int nLine = 1;
    int nChar = 0;

    ArrayStack stack;
    char ch;

    while((ch = getc(fp)) != EOF){
        if(ch == '\n') nLine++;

        nChar++;

        if(ch == '[' || '{' || '('){
            stack.push(ch);
            stack.display();
        }
        else if(ch == ']' || '}' || ')'){
            int prev = stack.pop();
            if((ch == ']' && prev != '[') ||
            (ch == '}' && prev != '{') ||
            (ch == ')' && prev != '(')) break; 
        }
    }
    fclose(fp);

    stack.display();

    if(!stack.isEmpty()){
        printf("Error\n");
    }
    else printf("ok");

    return stack.isEmpty();
}

int main(){

    checkMatching("./ArrayStack.hpp");
    return 0;
}