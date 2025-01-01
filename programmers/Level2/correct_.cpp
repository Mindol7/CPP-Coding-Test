#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
//gg//
using namespace std;

bool solution(string s){
    bool answer = true;
    stack<char> st;

    for(int i = 0; i<s.size(); ++i){
        if(st.empty() && s[i] == ')') return false;
        if(s[i] == '(') st.push(s[i]);
        else{
            if(st.top() == '(') st.pop();
        }
    }

    if(st.empty()) answer = true;
    else answer = false;

    return answer;
}

int main(){
    cout<<solution("()()")<<endl; // true
    cout<<solution("(())()")<<endl; // true
    cout<<solution(")()(")<<endl; // false
    cout<<solution("(()(")<<endl; // false
    cout<<solution(")()()()")<<endl;
    return 0;
}