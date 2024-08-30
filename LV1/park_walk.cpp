#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    pair<int, int> start_point;

    pair<int, int> end_point;
    
    vector<pair<int, int>> hurdle;

    end_point = make_pair(park.size()-1, park[0].size()-1); // x축, y축
    /* 시작 위치 찾기 */
    for(int i = 0; i<park.size(); ++i){
        for(int j = 0; j<park[0].size(); ++j){
            if(park[i][j] == 'S') start_point = make_pair(i, j);
            else if(park[i][j] == 'X') hurdle.push_back(make_pair(i, j));
        }
    }

    /* route 계산 */
    // 경계검사 및 장애물검사 필요
    
    for(auto cmd : routes){
        char pos_cmd = cmd[0];
        int move = cmd[2] - '0';
        bool meet_hurdle = false;
        bool out_of_bound = false;
        switch(pos_cmd){
            case 'E':
                if(start_point.second+move > end_point.second){
                    out_of_bound = true;
                    break;
                }
                else{
                    for(auto hurdle_idx : hurdle){
                        for(int i = 1; i<=move; ++i){
                            if(start_point.first == hurdle_idx.first && start_point.second + i == hurdle_idx.second){
                                meet_hurdle = true;
                                break;
                            }
                        }
                        if(meet_hurdle) break;
                    }
                }
                if(meet_hurdle || out_of_bound) break;

                start_point.second += move;
                break; 
                    
            case 'W':
                if(start_point.second-move < 0){
                    out_of_bound = true;
                    break;
                }
                else{
                    for(auto hurdle_idx : hurdle){
                        for(int i = 1; i<=move; ++i){
                            if(start_point.first == hurdle_idx.first && start_point.second - i == hurdle_idx.second){
                                meet_hurdle = true;
                                break;
                            }
                        }
                        if(meet_hurdle) break;
                    }
                }
                if(meet_hurdle || out_of_bound) break;

                start_point.second -= move;
                break;
                
            case 'S':
                if(start_point.first+move > end_point.first){
                    out_of_bound = true;
                    break;
                }
                else{
                    for(auto hurdle_idx : hurdle){
                        for(int i = 1; i<=move; ++i){
                            if(start_point.second == hurdle_idx.second && start_point.first + i == hurdle_idx.first){
                                meet_hurdle = true;
                                break;
                            }
                        }
                        if(meet_hurdle) break;
                    }
                }
                if(meet_hurdle || out_of_bound) break;

                start_point.first += move;
                break;

            case 'N':
                if(start_point.first-move < 0){
                    out_of_bound = true;
                    break;
                }
                else{
                    for(auto hurdle_idx : hurdle){
                        for(int i = 1; i<=move; ++i){
                            if(start_point.second == hurdle_idx.second && start_point.first - i == hurdle_idx.first){
                                meet_hurdle = true;
                                break;
                            }
                        }
                        if(meet_hurdle) break;
                    }
                }
                if(meet_hurdle || out_of_bound) break;

                start_point.first -= move;
                break;
        }
    }

    answer.push_back(start_point.first);
    answer.push_back(start_point.second);
    return answer;
}

int main(){
    vector<int> v1 = solution({"SOO", "OOO", "OOO"}, {"E 2", "S 2", "W 1"}); // 2,1
    
    for(auto i : v1){
        cout<<i<<" ";
    }cout<<endl;

    vector<int> v2 = solution({"SOO", "OXX", "OOO"}, {"E 2", "S 2", "W 1"}); // 0,1

    for(auto i : v2){
        cout<<i<<" ";
    }cout<<endl;

    vector<int> v3 = solution({"OSO", "OOO", "OXO", "OOO"}, {"E 2", "S 3", "W 1"}); // 0,0

    for(auto i : v3){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}