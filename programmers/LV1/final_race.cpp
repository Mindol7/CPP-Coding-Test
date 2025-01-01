#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;

    unordered_map<string, int> player_map;
    for(int i = 0; i<players.size(); ++i){
        player_map[players[i]] = i; // player 이름을 키로, 인덱스를 값으로
    }

    for(const auto &call : callings){
        int idx = player_map[call];
        
        swap(players[idx-1], players[idx]);

        player_map[players[idx]] = idx;
        player_map[players[idx-1]] = idx - 1;
    }
    answer = players;
    return answer;
}

int main(){
    vector<string> v1 = solution({"mumu", "soe", "poe", "kai", "mine"}
                        ,{"kai", "kai", "mine", "mine"});

    for(auto i : v1){
        cout<<i<<" ";
    }cout<<endl;
    
    return 0;
}