#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct fail_ratio{
    int stage;
    float failure;
}Fail_Ratio;

bool compare(Fail_Ratio &a, Fail_Ratio &b){
    if(a.failure == b.failure){
        return a.stage < b.stage;
    }
    return a.failure > b.failure;
}

vector<int> solution(int N, vector<int> stages){
    vector<int> answer;
    vector<Fail_Ratio> failure(N);
    vector<float> reach(N+2, 0.0);
    vector<float> fail(N+2, 0.0);

    int i = 0;
    float failure_ = 0.0f;
    while(i < N){
        for(auto j : stages){
            if(j >= i+1){
                reach[i]++;
            }
            if(j == i+1){
                fail[i]++;
            }
        }

        if(reach[i] == 0){
            failure_ = 0;
        }
        else{
            failure_ = fail[i] / reach[i];
        }
        failure[i].stage = i+1;
        failure[i].failure = failure_;
        i++;
    }

    sort(failure.begin(), failure.end(), compare);

    for(int k = 0; k < N; ++k){
        answer.push_back(failure[k].stage);
    }

    return answer;
}


int main(){
    vector<int> first_game = {2,1,2,6,2,4,3,3};
    vector<int> second_game = {4,4,4,4,4};
    vector<int> third_game = {4};
    vector<int> result;

    result = solution(5, first_game);

    for(auto i : result){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}