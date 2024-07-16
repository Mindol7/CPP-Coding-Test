#include <iostream>
#include <stack>

using namespace std;

string solution(int decimal){
    string answer = "";
    stack<int> stack;
    int r;
    while(!(decimal == 0)){
        stack.push(decimal % 2);
        decimal = decimal / 2;
    }

    while(!stack.empty()){
        answer += to_string(stack.top());
        stack.pop();
    }

    return answer;
}

int main(){
    cout<<solution(10)<<endl;
    cout<<solution(27)<<endl;
    cout<<solution(12345)<<endl;

    return 0;
}