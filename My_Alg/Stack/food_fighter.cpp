#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    vector<int> food_;
    for(int i = 1; i<food.size(); ++i){
        if(food[i] % 2 == 1){
            food[i] = food[i] - 1;
        }

        food[i] /= 2;
    }

    for(int i = 1; i<food.size(); ++i){
        for(int j = 1; j<=food[i]; ++j){
            if(food[i] == 0){
                break;
            }
            answer.push_back(i + '0');
        }
    }

    answer.push_back('0');

    for(int i = food.size()-1; i>0; --i){
        for(int j = 1; j<=food[i]; ++j){
            if(food[i] == 0){
                break;
            }
            answer.push_back(i + '0');
        }
    }

    return answer;
}

int main(){
    string s1 = solution({1,3,4,6});
    string s2 = solution({1,7,1,2});

    for(auto i : s1){
        cout<<i;
    }cout<<endl;

    for(auto i : s2){
        cout<<i;
    }cout<<endl;
    return 0;
}