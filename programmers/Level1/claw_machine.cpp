#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int moves_size = moves.size();
    int claw;

    stack<int> basket;

    for(int i = 0; i<moves_size; ++i){
        claw = moves[i];

        for(auto& board_line : board){
            if(board_line[claw-1] != 0){
                if(!(basket.empty())){
                    if(basket.top() == board_line[claw-1]){
                        basket.pop();
                        answer+=2;
                        board_line[claw-1] = 0;
                    }
                    else{
                        basket.push(board_line[claw-1]);
                        board_line[claw-1] = 0;
                    }
                }
                else{
                    basket.push(board_line[claw-1]);
                    board_line[claw-1] = 0;    
                }
                break;
            }
        }
    }

    return answer;
}
int main(){
    cout<<solution({{0,0,0,0,0}, {0,0,1,0,3}, {0,2,5,0,1}, {4,2,4,4,2}, {3,5,1,3,1}}, {1,5,3,5,1,2,1,4})<<endl; // 4

    return 0;
}