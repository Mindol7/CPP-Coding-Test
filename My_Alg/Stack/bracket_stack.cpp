#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool solution(string s){
    stack<char> stack;

    for(auto it = s.begin(); it != s.end(); ++it){
        if(*it == '('){
            stack.push(*it);
        }
        else{
            if(stack.top() == '('){
                stack.pop();
            }
        }
    }

    return stack.empty();
}

int main(){
    cout<<solution("(())()")<<endl;
    cout<<solution("((())()")<<endl;

    return 0;
}