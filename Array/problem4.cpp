#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers){
    vector<int> stu1 = {1, 2, 3, 4, 5};
    vector<int> stu2 = {2, 1, 2, 3, 2};
    vector<int> stu3 = {3, 3, 1, 1, 2};
    vector<int> top;

    int correct1 = 0;
    int correct2 = 0;
    int correct3 = 0;

    for(int i = 0; i < answers.size(); ++i){
        if(stu1[i] == answers[i]){
            correct1++;
        }
    }

    for(int i = 0; i < answers.size(); ++i){
        if(stu2[i] == answers[i]){
            correct2++;
        }
    }

    for(int i = 0; i < answers.size(); ++i){
        if(stu3[i] == answers[i]){
            correct3++;
        }
    }

    if(correct1 > correct2 && correct1 > correct3){
        top.push_back(1);
    }
    else if(correct2 > correct1 && correct2 > correct3){
        top.push_back(2);
    }
    else if(correct3 > correct1 && correct3 > correct2){
        top.push_back(3);
    }
    else if(correct1 == correct2 && correct1 > correct3){
        top.push_back(1);
        top.push_back(2);
    }
    else if(correct1 == correct3 && correct1 > correct2){
        top.push_back(1);
        top.push_back(3);
    }
    else if(correct2 == correct3 && correct2 > correct1){
        top.push_back(2);
        top.push_back(3);
    }
    else if(correct2 == correct3 && correct2 == correct1){
        top.push_back(1);
        top.push_back(2);
        top.push_back(3);
    }

    return top;
}

int main(){
    vector<int> answers1 = {1, 2, 3, 4, 5};
    answers1 = solution(answers1);

    vector<int> answers2 = {1, 3, 2, 4, 2};
    answers2 = solution(answers2);

    for(auto i : answers1){
        cout<<i<<" ";
    }
    cout<<endl;

    for(auto j : answers2){
        cout<<j<<" ";
    }
    cout<<endl;

    return 0;
}