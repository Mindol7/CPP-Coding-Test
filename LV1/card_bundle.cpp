#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    vector<bool> cards1_flag(cards1.size(), false);
    vector<bool> cards2_flag(cards2.size(), false);

    for(int i = 0; i<goal.size(); ++i){
        auto it = find(cards1.begin(), cards1.end(), goal[i]);
        if(it != cards1.end()){
            if(distance(cards1.begin(), it) == 0){
                cards1_flag[0] = true;
            }
            else{
                for(int j = 0; j<distance(cards1.begin(), it); ++j){
                    if(cards1_flag[j] == false){
                        return "No";
                    }
                }
            }
            cards1_flag[distance(cards1.begin(), it)] = true;
        }
        else{
            auto it_ = find(cards2.begin(), cards2.end(), goal[i]);
            if(it_ != cards2.end()){
                if(distance(cards2.begin(), it_) == 0){
                    cards2_flag[0] = true;
                }
                else{
                    for(int j = 0; j<distance(cards2.begin(), it_); ++j){
                        if(cards2_flag[j] == false){
                            return "No";
                        }
                    }
                }
                cards2_flag[distance(cards2.begin(), it_)] = true;
            }
            else{
                return "No";
            }
        }
    }
    return "Yes";
}

int main(){
    cout<<solution({"i", "drink", "water"}, {"want", "to"}, {"i", "want", "to", "drink", "water"})<<endl;
    cout<<solution({"i", "water", "drink"}, {"want", "to"}, {"i", "want", "to", "drink", "water"})<<endl;
    return 0;
}