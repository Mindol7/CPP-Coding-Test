#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;

    string point_color = board[h][w];
    vector<bool> flag(4, false);

    for(int i = 0; i<4; ++i){
        // 상 검사
        if(i == 0){
            int dh = h+1;
            if(dh >= board.size()){
                continue;
            }
            else{
                if(board[dh][w] == point_color){
                    flag[0] = true;
                }
            }
        }
        // 하 검사
        if(i == 1){
            int dh = h-1;
            if(dh < 0){
                continue;
            }
            else{
                if(board[dh][w] == point_color){
                    flag[1] = true;
                }
            }
        }
        // 좌 검사
        if(i == 2){
            int dw = w-1;
            if(dw < 0){
                continue;
            }
            else{
                if(board[h][dw] == point_color){
                    flag[2] = true;
                }
            }
        }
        // 우 검사
        if(i == 3){
            int dw = w+1;
            if(dw >= board[0].size()){
                continue;
            }
            else{
                if(board[h][dw] == point_color){
                    flag[3] = true;
                }
            }
        }
    }
    
    for(int i = 0; i<4; i++){
        if(flag[i]){
            answer++;
        }
    }

    return answer;
}

int main(){
    cout<<solution({{"blue", "red", "orange", "red"},
                    {"red", "red", "blue", "orange"},
                    {"blue", "orange", "red", "red"},
                    {"orange", "orange", "red", "blue"}}, 1, 1)<<endl; // 2
    
    cout<<solution({{"yellow", "green", "blue"},
                    {"blue", "green", "yellow"},
                    {"yellow", "blue", "blue"}}, 0, 1)<<endl; // 1


    return 0;
}