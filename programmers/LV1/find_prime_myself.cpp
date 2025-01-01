#include <iostream>
#include <vector>

using namespace std;

int solution(int n){
    int answer = 0;
    vector<bool> vec(n+1, true);

    vec[0] = vec[1] = false;

    for(int i = 2; i*i<n; ++i){
        if(vec[i]){
            for(int j = i*i; j<=n; j+=i){ // 이미 그전에 커버될것이기때문에 제곱부터 시작함, 그리고 배수씩 증가시켜줌
                vec[j] = false;
            }
        }
    }

    return answer;
}

int main(){
    cout<<solution(10)<<endl;
    cout<<solution(5)<<endl;

    return 0;
}