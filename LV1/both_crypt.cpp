#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    int count = 0;
    for(int i = 0; i<s.size(); ++i){
            for(int j = 1; j<=index; ++j){
                if(skip.find(s[i]+j) != string::npos){
                    s[i]++;
                }
                if(s[i] + j> 122){
                    s[i] = s[i] - 26;
                }
                
                
            }
            s[i] = s[i] + index;

            if(s[i] > 122){
                s[i] = s[i] - 26;
            }
            for(int j = 1; j<=index; ++j){
                    if(skip.find(s[i]+j) != string::npos){
                        s[i]++;
                    }
                    if(s[i] + j - 1> 122){
                        s[i] = s[i] - 26;
                    }
                }
        
        answer.push_back(s[i]);
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