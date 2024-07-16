#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<string> v;
    string word;
    int j = 0;
    for(int i = 0; i<s.size(); ++i){
        if(s[i] != ' '){
            if(j%2 == 0 && 97 <= s[i] && 122 >= s[i]){
                // cout<<s[i];
                s[i] = s[i] - 32;
            }
            else if(j%2 == 1 && 65 <= s[i] && 90 >= s[i]){
                // cout<<s[i];
                s[i] = s[i] + 32;
            }
        }
        else{
            ++i;
            if(j%2 == 0 && 97 <= s[i] && 122 >= s[i]){
                cout<<s[i];
                s[i] = s[i] - 32;
            }
            else if(j%2 == 1 && 65 <= s[i] && 90 >= s[i]){
                cout<<s[i];
                s[i] = s[i] + 32;
            }
        }
        
    }

    answer = s;
    return answer;
}

int main(){
    cout<<solution("try hello world")<<endl;
    return 0;
}
