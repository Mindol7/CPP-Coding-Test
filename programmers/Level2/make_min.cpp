#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
//
using namespace std;

int solution(vector<int> A, vector<int> B){
    int answer = 0;
    sort(A.begin(), A.end()); sort(B.rbegin(), B.rend());
    
    for(int i = 0; i<A.size(); ++i){
        answer+= A[i] * B[i];
    }
    return answer;
}

int main(){
    cout<<solution({1,4,2}, {5,4,4})<<endl; // 29
    cout<<solution({1,2}, {3,4})<<endl; // 10
    return 0;
}