#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool inspect(string str_){
    bool flag = false;
    stack<char> stack;

    for(int i = 0; i<str_.size(); ++i){
        switch(str_[i]){
            case '(':
            case '[':
            case '{':
                stack.push(str_[i]);
                break;
            case ')':
            case ']':
            case '}':
                if((stack.empty() && str_[i] == ')')
                || (stack.empty() && str_[i] == ']')
                || (stack.empty() && str_[i] == '}')){
                    return false;
                }

                if(!stack.empty()){
                    if((stack.top() == '(' && str_[i] == ')')
                    || (stack.top() == '[' && str_[i] == ']')
                    || (stack.top() == '{' && str_[i] == '}')){
                        stack.pop();
                        flag = true;
                        break;
                    }
                    else{
                        return false;
                    }
                }
        }
    }

    if(stack.empty()){
        return flag;
    }
    else{
        return false;
    }
}

int solution(string s){
    int answer = 0;

    for(int i = 0; i<s.size(); ++i){
        string str = "";

        if(i != 0){
            for(int j = i; j<s.size(); ++j){
                str.push_back(s[j]);
            }
            for(int k = 0; k<i; ++k){
                str.push_back(s[k]);
            }
        }
        else{
            str = s;
        }

        if(inspect(str) == true){
            answer++;
        }
    }
    return answer;
}

int main(){
    cout<<solution("[](){}")<<endl;
    cout<<solution("}]()[{")<<endl;
    cout<<solution("[)(]")<<endl;
    cout<<solution("}}}")<<endl;
    cout<<solution("({)}")<<endl;
    cout<<solution("(){{")<<endl;
}
