#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    int count = 0;
    vector<int> aliquot;

    for(int i = 1; i<=number; ++i){
        int sqrt_num = sqrt(i);
        
        for(int j = 1; j<=sqrt_num; ++j){
            if(i%j == 0){
                count++;
                if(j != i/j){
                    count++;
                }
            }
        }
        aliquot.push_back(count);
        count = 0;
    }    

    for(int i = 0; i<number; ++i){
        if(aliquot[i] > limit){
            answer += power;
        }
        else{
            answer += aliquot[i];
        }
    }

    return answer;
}

int count(int n){
    int cnt = 0;

    for(int i = 1; i*i <= n; ++i){
        if(n%i)continue;
        if(i*i==n) cnt+=1;
        else cnt+=2;
    }

    return cnt;
}

int main(){
    cout<<solution(5,3,2)<<endl;
    cout<<solution(10,3,2)<<endl;
    // cout<<solution(99999,3,2)<<endl;

    return 0;
}