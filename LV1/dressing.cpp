#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int finish_time = attacks[attacks.size()-1][0]; 
    int continuous_success = 0;

    int max_health = health;

    for(int i = 0; i<=finish_time; ++i){
        if(i == attacks[0][0]){
            health -= attacks[0][1];
            if(health <= 0) return -1;
            continuous_success = 0;
            attacks.erase(attacks.begin());          
        }
        else{
            continuous_success++;
            if(continuous_success == bandage[0]){
                health += bandage[1] + bandage[2];
                continuous_success = 0;
                if(health >= max_health) health = max_health;
            }
            else{
                health += bandage[1];
                if(health >= max_health) health = max_health;
            }
        }
    }
    answer = health;
    return answer;
}

// #include <string>
// #include <vector>

// using namespace std;

// int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
//     int maxhealth = health, time = 0;
//     for(int i=0;i<attacks.size();i++){
//         int dTime = attacks[i][0];
//         int damage=attacks[i][1];
//         int diff = dTime - time-1;
//         health += diff*bandage[1] +diff/bandage[0] * bandage[2];
//         if(health > maxhealth) health = maxhealth;
//         health-=damage;
//         time = dTime;
//         if(health<=0) break;
//     }
//     return health<=0 ? -1:health;
// }

int main(){
    cout<<solution({5,1,5}, 30, {{2,10}, {9,15}, {10,5}, {11,5}})<<endl; // 5
    cout<<solution({3,2,7}, 20, {{1,15}, {5,16}, {8,6}})<<endl; // -1
    cout<<solution({4,2,7}, 20, {{1,15}, {5,16}, {8,6}})<<endl; // -1
    cout<<solution({1,1,1}, 5, {{1,2}, {3,2}})<<endl; // 3

    return 0;
}