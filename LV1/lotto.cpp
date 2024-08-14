#include <iostream>
#include <vector>

using namespace std;

int top_rank(vector<int> lottos, vector<int> win_nums){
    int count = 0;
    for(int i = 0; i<lottos.size(); ++i){
        if(lottos[i] == 0){
                count++;
                continue;
            }
        for(int j = 0; j<lottos.size(); ++j){
            
            if(lottos[i] == win_nums[j]){
                count++;
            }
        }
    }
    if(count == 0 || count == 1){
        return 6;
    }
    else{
        return lottos.size() - count + 1;
    }    
}

int low_rank(vector<int> lottos, vector<int> win_nums){
    int count = 0;

    for(int i = 0; i<lottos.size(); ++i){
        for(int j = 0; j<lottos.size(); ++j){
            if(lottos[i] == win_nums[j]){
                count++;
            }
        }
    }

    if(count == 0 || count == 1){
        return 6;
    }
    else{
        return lottos.size() - count + 1;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    bool zero_flag = true;
    int top = 0, low = 0;
    /* 모든 요소가 0일때 1등도 가능, 6등도 가능*/
    for(int i = 0; i<lottos.size(); ++i){
        if(lottos[i] != 0){
            zero_flag = false;
            break;
        }
    }

    if(zero_flag){  
        answer.push_back(1);
        answer.push_back(6);
        return answer;
    }

    top = top_rank(lottos, win_nums);
    low = low_rank(lottos, win_nums);

    answer.push_back(top);
    answer.push_back(low);



    return answer;
}

int main(){
    vector<int> v1 = solution({44,1,0,0,31,25}, {31,10,45,1,6,19}); // 3,5
    vector<int> v2 = solution({0,0,0,0,0,0}, {38,19,20,40,15,25}); // 1,6
    vector<int> v3 = solution({45,4,35,20,3,9}, {20,9,3,45,4,35}); // 1,1

    for(auto &i : v1){
        cout<<i<<" ";
    }cout<<endl;

    for(auto &i : v2){
        cout<<i<<" ";
    }cout<<endl;

    for(auto &i : v3){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}