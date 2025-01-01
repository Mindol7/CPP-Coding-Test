#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> stack;
    
    for(char ch : s){
        if(!stack.empty() && ch == stack.top()){
            stack.pop();
        }
        else{
            stack.push(ch);
        }
    }

    if(stack.empty()){
        answer = 1;
    }
    else{
        answer = 0;
    }
    return answer;
}

int main(){
    cout<<solution("baabaa")<<endl;
    cout<<solution("cdcd")<<endl;
    cout<<solution("baaabaaa")<<endl;

    return 0;
}