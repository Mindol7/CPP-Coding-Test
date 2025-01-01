#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i<skip.size(); ++i){
        alpha.erase(find(alpha.begin(), alpha.end(), skip[i]));
    }

    for(int i = 0; i<s.size(); ++i){
        int change = alpha.find(s[i]) + index;
        while(change >= alpha.length()){
            change -= alpha.length();
        }
        answer += alpha[change];
    }

    return answer;
}

int main(){
    cout<<solution("aukks", "wbdq", 5)<<endl;
    cout<<solution("z", "a", 1)<<endl;
    cout<<solution("a", "bcdefghijk", 20)<<endl; // o
    cout<<solution("z","abcdefghij",20)<<endl; // n
    cout<<solution("abcde","bcd",2)<<endl; // "ffffg"
    cout<<solution("yyyyy","za",2)<<endl; // ccccc
    cout<<solution("ybcde","az",1)<<endl; // bcdef
    cout<<solution("zzzzzz","abcdefghijklmnopqrstuvwxy",6)<<endl; // "zzzzzz"
    cout<<solution("bcdefghijklmnopqrstuvwxyz", "a", 1)<<endl; // "cdefghijklmnopqrstuvwxyzb"
    return 0;
}