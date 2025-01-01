#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int next_idx = 0;
    int dart_flag = 0; // 0 -> no opt, 1 -> *, 2 -> #
    int score = 0;
    int before_score = 0;
    char bonus, option;
    int count = 0; 
    bool ten_flag = false;

    for(int i = 0; count != 3; i=next_idx){
        i = next_idx;
        if(count != 2){   
            if(dartResult[next_idx] == '1' && dartResult[next_idx+1] == '0'){
                ten_flag = true;
                for(int j = i+1; !isdigit(dartResult[j]); j++){
                    next_idx++;
                }
                i++;
                next_idx+=3;
                
            }
            else{
                ten_flag = false;
                for(int j = i+1; !isdigit(dartResult[j]); j++){
                    next_idx++;
                }
                next_idx++;
            }

        }
        else{
            if(dartResult[next_idx] == '1' && dartResult[next_idx+1] == '0'){
                ten_flag = true;
                i++;
            }
            else{
                ten_flag = false;
            }
            
            next_idx = dartResult.size();
        }

        cout<<"I : "<<i<<endl;
        cout<<"next_idx : "<<next_idx<<endl;
        cout<<"Flag : "<<ten_flag<<endl;

        if(next_idx - i == 2){ // no option, only cal
            if(ten_flag){
                score = 10;
                bonus = dartResult[i+1];
            }
            else{
                score = dartResult[i] - '0';
                bonus = dartResult[i+1];
            }
            
            dart_flag = 0;

            if(bonus == 'S'){
                answer += pow(score, 1);
                before_score = pow(score, 1);
            }
            else if(bonus == 'D'){
                answer += pow(score, 2);
                before_score = pow(score, 2);
            }
            else if(bonus == 'T'){
                answer += pow(score, 3);
                before_score = pow(score, 3);
            }
        }
        else if(next_idx - i == 3){ // option ok
            if(ten_flag){
                score = 10;
                bonus = dartResult[i+1];
                option = dartResult[i+2];
            }
            else{
                score = dartResult[i] - '0';
                bonus = dartResult[i+1];
                option = dartResult[i+2];
            }

            if(option == '*'){
                answer -= before_score;
                if(dart_flag == 1){ // *
                    if(bonus == 'S'){
                        answer += before_score * 2 + pow(score,1) * 2;
                        before_score =  pow(score,1) * 2;
                    }
                    else if(bonus == 'D'){
                        answer += before_score * 2 + pow(score,2) * 2;
                        before_score =  pow(score,2) * 2;
                    }
                    else if(bonus == 'T'){
                        answer += before_score * 2 + pow(score,3) * 2;
                        before_score =  pow(score,3) * 2;
                    }
                }
                else if(dart_flag == 2){ // #
                    if(bonus == 'S'){
                        answer += ((before_score * 2)) + pow(score,1) * 2;
                        before_score =  pow(score,1) * 2;
                    }
                    else if(bonus == 'D'){
                        answer += ((before_score * 2)) + pow(score,2) * 2;
                        before_score =  pow(score,2) * 2;
                    }
                    else if(bonus == 'T'){
                        answer += ((before_score * 2)) + pow(score,3) * 2;
                        before_score =  pow(score,3) * 2;
                    }
                }
                else{
                    if(bonus == 'S'){
                        answer += (before_score + pow(score,1)) * 2;
                        before_score =  pow(score,1) * 2;
                    }
                    else if(bonus == 'D'){
                        answer += (before_score + pow(score,2)) * 2;
                        before_score =  pow(score,2) * 2;
                    }
                    else if(bonus == 'T'){
                        answer += (before_score + pow(score,3)) * 2;
                        before_score =  pow(score,3) * 2;
                    }
                }
                
                dart_flag = 1;
            }
            else if(option == '#'){
                if(bonus == 'S'){
                    answer += pow(score, 1) * (-1);
                    before_score = pow(score, 1) * (-1);
                }
                else if(bonus == 'D'){
                    answer += pow(score, 2) * (-1);
                    before_score = pow(score, 2) * (-1);
                }
                else if(bonus == 'T'){
                    answer += pow(score, 3) * (-1);
                    before_score = pow(score, 3) * (-1);
                }
                dart_flag = 2;
            }
        }
        cout<<"Score : "<<score<<endl;
        cout<<"Answer : "<<answer<<endl;
        count++;   
    }
    return answer;
}

int main(){
    cout<<solution("1S2D*3T")<<endl; // 37
    cout<<solution("1D2S#10S")<<endl; // 9, no
    cout<<solution("1D2S0T")<<endl; // 3
    cout<<solution("1S*2T*3S")<<endl; // 23, no
    cout<<solution("1D#2S*3S")<<endl; // 5, no, 계산 로직 잘못된듯함
    cout<<solution("1T2D3D#")<<endl; // -4
    cout<<solution("1D2S3T*")<<endl; // 59
    cout<<solution("10S0D4D*")<<endl;
    return 0;
}