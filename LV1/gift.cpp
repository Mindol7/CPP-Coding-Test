#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    unordered_map<string, vector<string>> gift_table;
    string tx_gift, rx_gift; 
    unordered_map<string, int> friends_idx;
    vector<vector<int>> real_gift_table(friends.size(), vector<int>(friends.size(),0));

    int idx=0;

    for(auto list : friends){
        friends_idx[list] = idx;
        ++idx;
    }

    for(auto list : gifts){
        stringstream ss(list);
        ss>>tx_gift>>rx_gift;
        gift_table[tx_gift].push_back(rx_gift);
    }
    
    int key_idx = 0;
    for(auto key : friends){
        for(auto value : gift_table[key]){
            if(key_idx == friends_idx[value]){
                real_gift_table[key_idx][key_idx] = -1;
            }
            else{
                real_gift_table[key_idx][friends_idx[value]] += 1;
            }
        }
        key_idx++;
    }
    vector<int> gift_rate;
    for(int i = 0; i<friends.size(); ++i){
        int tx = 0, rx = 0;
        for(int j = 0; j<friends.size(); ++j){
            tx += real_gift_table[i][j];
            rx += real_gift_table[j][i];
        }
        gift_rate.push_back(tx-rx);
    }
    
    vector<int> preview_gift(friends.size(), 0);

    for(int i = 0; i<friends.size(); ++i){
        for(int j = i; j<friends.size(); ++j){
            if(i == j) continue;
            else{
                if(real_gift_table[i][j] == real_gift_table[j][i]){
                    if(gift_rate[i] > gift_rate[j]) preview_gift[i]++;
                    else if(gift_rate[i] < gift_rate[j]) preview_gift[j]++;
                }
                
                else if(real_gift_table[i][j] > real_gift_table[j][i]){
                    preview_gift[i]++;
                }
                
                else{
                    preview_gift[j]++;
                }
            }   
        }
    }
    answer = *max_element(preview_gift.begin(), preview_gift.end());
    return answer;
}

int main(){
    cout<<solution({"muzi", "ryan", "frodo", "neo"},{"muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"})<<endl; // 2
    cout<<solution({"joy", "brad", "alessandro", "conan", "david"}, {"alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david"})<<endl; // 4
    cout<<solution({"a", "b", "c"}, {"a b", "b a", "c a", "a c", "a c", "c a"})<<endl; // 0

    return 0;
}