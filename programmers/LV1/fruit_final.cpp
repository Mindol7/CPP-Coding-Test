#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.rbegin(), score.rend());   

    for(int i = 0; i+m<=score.size(); i+=m){
        answer += score[i+m-1] * m;
    }

    return answer;
}

int main(){
    cout<<solution(3, 4, {1,2,3,1,2,3,1})<<endl; // 3 3 2 2 1 1 1
    cout<<solution(4, 3, {4,1,2,2,4,4,4,4,1,2,4,2})<<endl; // 4 4 4 4 4 4 2 2 2 2 1 1

    return 0;
}