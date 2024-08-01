#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int var1, var2, res1, res2;
    for(int i = 0; i<n; ++i){
        var1 = arr1[i] & 0x0001f;
        res1 = (var1 << 4) | (var1 << 2) | (var1 >> 2) | (var1 >> 4);
        var2 = arr2[i] & 0x0001f;
        res2 = (var2 << 4) | (var2 << 2) | (var2 >> 2) | (var2 >> 4);

    }
    

    return answer;
}

int main(){
    vector<string> str1 = solution(5, {9,20,28,18,11}, {30,1,21,17,28});
    vector<string> str2 = solution(6, {46,33,33,22,31,50}, {27,56,19,14,14,10});

    for(auto i : str1){
        cout<<i<<" ";
    }cout<<endl;

    for(auto i : str2){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}