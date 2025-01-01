#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int same_count = 0;
    int not_same_count = 0;
    int idx = 0;

    while(true){
        if((idx+2 == s.size()) || (idx+1 == s.size()) || (idx == s.size())){
            answer++;
            return answer;
        }
        char x = s[idx];
        same_count++;
        for(int i = idx+1; i<s.size() || i == s.size(); ++i){
            if(i == s.size()){
                if(same_count == not_same_count){
                    answer++;
                    return answer;
                }
            }
            if(i != s.size() && same_count == not_same_count){
                idx = i;
                answer++;
                break;
            }
            else{
                if(s[i] == x){
                    same_count++;
                }
                else{
                    not_same_count++;
                }
            }

        }
        if(same_count != not_same_count){
            answer++;
            return answer;
        }
        same_count = 0, not_same_count = 0;
    }
    return answer;
}

int main(){
    cout<<solution("banana")<<endl; // 3
    cout<<solution("abracadabra")<<endl; // 6
    cout<<solution("aaabbaccccabba")<<endl; // 3
    cout<<solution("aaabb")<<endl;
    cout<<solution("abaaabb")<<endl;
    cout<<solution("aabcddnaaaaccbb")<<endl;
    cout<<solution("abcde")<<endl;
    cout<<solution("aaabbbabcde")<<endl;
    cout<<solution("abaab")<<endl;
    cout<<solution("aab")<<endl;
    cout<<solution("aabb")<<endl;
    return 0;
}