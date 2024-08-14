#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer(targets.size(), 0);
    bool flag = false;
    int count = 0;
    for(int i = 0; i < targets.size(); ++i){
        for(int j = 0; j < targets[i].size(); ++j){
            vector<int> idx;
            for(int k = 0; k<keymap.size(); ++k){
                if(keymap[k].find(targets[i][j]) != string::npos){
                    flag = true;
                    idx.push_back(keymap[k].find(targets[i][j]));
                }
            }
            if(flag == false){
                answer[i] = -1;
                break;
            }
            else{
                count = *(min_element(idx.begin(), idx.end())) + 1;
                answer[i] += count;
                flag = false;
            }
        }
    }

    return answer;
}

int main(){
    vector<int> v1 = solution({"ABACD", "BCEFD"}, {"ABCD", "AABB"}); // 9,4
    vector<int> v2 = solution({"AA"}, {"B"}); // -1
    vector<int> v3 = solution({"AGZ", "BSSS"}, {"ASA", "BGZ"}); // 4,6
    vector<int> v4 = solution({"AB", "AAB"}, {"B"});
    vector<int> v5 = solution({"ABCE"}, {"ABDE"});

    for(auto i : v1){
        cout<<i<<" ";
    }cout<<endl;

    for(auto i : v2){
        cout<<i<<" ";
    }cout<<endl;

    for(auto i : v3){
        cout<<i<<" ";
    }cout<<endl;

    for(auto i : v4){
        cout<<i<<" ";
    }cout<<endl;

    for(auto i : v5){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}