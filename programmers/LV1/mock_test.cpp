#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int problem_size = answers.size();
    vector<int> v1_pattern = {1,2,3,4,5};
    vector<int> v2_pattern = {2,1,2,3,2,4,2,5};
    vector<int> v3_pattern = {3,3,1,1,2,2,4,4,5,5};
    vector<int> v1_answer, v2_answer, v3_answer;

    for(int i = 0; i<problem_size; ++i){
        if(i > v1_pattern.size()-1){
            v1_answer.push_back(v1_pattern[i%v1_pattern.size()]);
        }
        else{    
            v1_answer.push_back(v1_pattern[i]);
        }
        if(i > v2_pattern.size()-1){
            v2_answer.push_back(v2_pattern[i%v2_pattern.size()]);
        }
        else{    
            v2_answer.push_back(v2_pattern[i]);
        }
        if(i > v3_pattern.size()-1){
            v3_answer.push_back(v3_pattern[i%v3_pattern.size()]);
        }
        else{
            v3_answer.push_back(v3_pattern[i]);
        }
    }

    int v1_count = 0, v2_count = 0, v3_count = 0;

    for(int i = 0; i<problem_size; ++i){
        if(v1_answer[i] == answers[i]){
            v1_count++;
        }
        if(v2_answer[i] == answers[i]){
            v2_count++;
        }
        if(v3_answer[i] == answers[i]){
            v3_count++;
        }
    }

    if(v1_count > v2_count && v1_count > v3_count){
        answer.push_back(1);
    }else if(v2_count > v1_count && v2_count > v3_count){
        answer.push_back(2);
    }else if(v3_count > v1_count && v3_count > v2_count){
        answer.push_back(3);
    }else if(v1_count == v2_count && v1_count > v3_count){
        answer.push_back(1);
        answer.push_back(2);
    }else if(v1_count == v3_count && v1_count > v2_count){
        answer.push_back(1);
        answer.push_back(3);
    }else if(v2_count == v3_count && v2_count > v1_count){
        answer.push_back(2);
        answer.push_back(3);
    }else if(v1_count == v2_count && v1_count == v3_count){
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
    }
    return answer;
}

int main(){
    vector<int> v1 = solution({1,2,3,4,5});
    vector<int> v2 = solution({1,3,2,4,2});

    for(auto i : v1){
        cout<<i<<" ";
    }cout<<endl;

    for(auto i : v2){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}