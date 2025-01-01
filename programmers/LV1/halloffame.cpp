#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> hall;
    int i = 0;

    if(k>=score.size()){
        for(int i = 0; i<score.size(); ++i){
            hall.push_back(score[i]); // 10 | 10,100 | 10,100,20
            sort(hall.begin(), hall.end());
            answer.push_back(hall[0]);            
        }
    }
    else{
        for(i = 0; i<k; ++i){
            hall.push_back(score[i]); // 10 | 10,100 | 10,100,20
            sort(hall.begin(), hall.end());
            answer.push_back(hall[0]);
        }

        while(i<score.size()){
            sort(hall.begin(), hall.end());
            
            if(hall[0] < score[i]){
                hall[0] = score[i];
                sort(hall.begin(), hall.end());
                answer.push_back(hall[0]);
            }
            else{
                answer.push_back(hall[0]);
            }
            i++;
        }
    }
    return answer;
}

int main(){
    vector<int> v1 = solution(3, {10, 100, 20 ,150, 1, 100, 200});
    vector<int> v2 = solution(4, {0, 300, 40, 300, 20 ,70, 150, 50, 500, 1000});
    vector<int> v3 = solution(8, {200,200,200,200,200,200,200});

    for(auto i : v1){
        cout<<i<<" ";
    }cout<<endl;

    for(auto i : v2){
        cout<<i<<" ";
    }cout<<endl;

    for(auto i : v3){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}