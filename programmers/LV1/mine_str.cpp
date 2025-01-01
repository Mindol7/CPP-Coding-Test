#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    sort(strings.begin(), strings.end(), [n](const string &str1, const string &str2) {
        if(str1[n] != str2[n]){
            return str1[n] < str2[n];
        }
        else{
            return str1 < str2;
        }
    });

    return strings;
}

int main(){
    vector<string> str1 = solution({"sun", "bed", "car"}, 1);
    vector<string> str2 = solution({"abce", "abcd", "cdx"}, 2);

    for(auto i : str1){
        cout<<i<<" ";
    }cout<<endl;

    for(auto i : str2){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}