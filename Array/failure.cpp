#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, float> &a, pair<int, float> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages){
    vector<int> answer;
    vector<float> challenger(N+2, 0.0);
    vector<float> fail(N+2, 0.0);

    for(int i = 0; i < stages.size(); i++){
        for(int j = 1; j <= stages[i]; j++)
            challenger[j]++; // 스테이지에 도달한 적 있는 사람
        

        fail[stages[i]]++; // 스테이지에 실패한 사람
    }

     vector<pair<int, float>> failRatio(N);

    for(int i = 0; i < N; i++){
        failRatio[i].first = i+1;

        if(challenger[i+1] == 0){
            failRatio[i].second = 0;
        }
        else{
            failRatio[i].second = fail[i+1] / challenger[i+1];
        }
    }

    sort(failRatio.begin(), failRatio.end(), compare);

    for(int i = 0; i < N; i++){
        answer.push_back(failRatio[i].first);
    }

    return answer;
}

int main(){
    vector<int> v1 = {2,1,2,6,2,4,3,3};
    vector<int> v2 = {4,4,4,4,4};
    
    vector<int> v3 = solution(4, v2);

    for(auto i : v3){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}