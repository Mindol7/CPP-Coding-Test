#include <iostream>
#include <vector>

using namespace std;

int solution(int n){
    int answer = 0;
    vector<bool> vec(n+1, false);

    vec[0] = vec[1] = false;

    for(int i = 2; i*i<n; ++i){
        if(vec[i]){
            for(int j = i*i; j<=n; j += i){
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