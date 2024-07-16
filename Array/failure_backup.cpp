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
    int i = 0;
    float failure_ = 0.0f;
    while(i < N){
        int challenger = 0;
        for(auto j : stages){
            if(j == i+1){
                challenger++;
            }
        }

        failure_ = static_cast<float>(challenger) / static_cast<float>(stages.size());
        failure[i].stage = i+1;
        failure[i].failure = failure_;

        stages.erase(remove(stages.begin(), stages.end(), i+1), stages.end());

        i++;
    }

    sort(failure.begin(), failure.end(), compare);

    for(int k = 0; k < N; ++k){
        answer.push_back(failure[k].stage);
    }

    return answer;
}