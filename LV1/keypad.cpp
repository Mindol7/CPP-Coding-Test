#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left_x = -1, right_x = 1;
    int left_y = 0, right_y = 0;
    int x, y;

    for(int i = 0; i<numbers.size(); ++i){
        switch(numbers[i]){
            case 1:case 4:case 7:case 10:
                answer += 'L';
                left_x = -1;
                if(numbers[i] == 1) left_y = 3;
                else if(numbers[i] == 4) left_y = 2;
                else if(numbers[i] == 7) left_y = 1;
                else left_y = 0;
                break;

            case 3:case 6:case 9:case 12:
                answer += 'R';
                right_x = 1;
                if(numbers[i] == 3) right_y = 3;
                else if(numbers[i] == 6) right_y = 2;
                else if(numbers[i] == 9) right_y = 1;
                else right_y = 0;
                break;

            case 2:case 5:case 8:case 0:
                x=0;
                if(numbers[i] == 2)y=3;
                else if(numbers[i] == 5)y=2;
                else if(numbers[i] == 8)y=1;
                else if(numbers[i] == 0)y=0;
                
                if(abs(x-left_x) + abs(y-left_y) == abs(x-right_x) + abs(y-right_y)){
                    if(hand == "left"){
                        answer += 'L';
                        left_x = 0;
                        if(numbers[i] == 2) left_y=3;
                        else if(numbers[i] == 5) left_y=2;
                        else if(numbers[i] == 8) left_y=1;
                        else left_y = 0;
                    }
                    else{
                        answer += 'R';
                        right_x = 0;
                        if(numbers[i] == 3) right_y=3;
                        else if(numbers[i] == 6) right_y=2;
                        else if(numbers[i] == 9) right_y=1;
                        else right_y = 0;
                    } 
                }
                
                else{
                    if(numbers[i] == 2){
                        y = 3;
                        if(abs(x-left_x) + abs(y-left_y) > abs(x-right_x) + abs(y-right_y)){
                            right_x = 0;
                            right_y = 3;
                            answer += 'R';
                        } 
                        else{
                            left_x = 0;
                            left_y = 3;
                            answer += 'L';
                        }          
                    }
                    else if(numbers[i] == 5){
                        y = 2;
                        if(abs(x-left_x) + abs(y-left_y) > abs(x-right_x) + abs(y-right_y)){
                            right_x = 0;
                            right_y = 2;
                            answer += 'R';
                        } 
                        else{
                            left_x = 0;
                            left_y = 2;
                            answer += 'L';
                        }
                    }
                    else if(numbers[i] == 8){
                        y = 1;
                        if(abs(x-left_x) + abs(y-left_y) > abs(x-right_x) + abs(y-right_y)){
                            right_x = 0;
                            right_y = 1;
                            answer += 'R';
                        } 
                        else{
                            left_x = 0;
                            left_y = 1;
                            answer += 'L';
                        }
                    }
                    else if(numbers[i] == 0){
                        y = 0;
                        if(abs(x-left_x) + abs(y-left_y) > abs(x-right_x) + abs(y-right_y)){
                            right_x = 0;
                            right_y = 0;
                            answer += 'R';
                        } 
                        else{
                            left_x = 0;
                            left_y = 0;
                            answer += 'L';
                        }
                    }
                }
                break;
        }
    }
    return answer;
}

int main(){
    cout<<solution({1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right")<<endl;
    cout<<solution({7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2}, "left")<<endl;
    cout<<solution({1,2,3,4,5,6,7,8,9,0}, "right")<<endl;
    cout<<solution({0,5,8,2}, "left")<<endl;
    cout<<solution({3,7,5,2}, "left")<<endl;
    cout<<solution({0,0,0,0}, "left")<<endl;
    return 0;
}