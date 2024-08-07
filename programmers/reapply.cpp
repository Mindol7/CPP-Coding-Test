#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    vector<bool> paint(n+1, true);

    if(m == 1){
        return section.size();
    }

    for(int i = 0; i<section.size(); ++i){
        paint[section[i]] = false;
    }

    int flag_count = 0; // 롤러의 위치 조정 필요
    int roller_idx = 0;

    for(int i = section[0]; !paint[section[section.size()-1]]; i = roller_idx){
        for(int k = i; k<i+m; ++k){
            if(k >= paint.size()){
                break;
            }
            if(paint[k] == false){
                flag_count++;
            }
        }

            if(flag_count == 0){
                answer--;
            }

        for(int j = i; j<i+m; ++j){
            if(j >= paint.size()){
                break;
            }
            paint[j] = true;
        }
        answer++;
        flag_count = 0;

        for(int f = i; f<paint.size(); ++f){
            if(paint[f] == false){
                roller_idx = f;
                break;
            }
        }
    }

    return answer;
}

int main(){
    cout<<solution(8, 4, {2,3,6})<<endl;
    cout<<solution(5, 4, {1,3})<<endl;
    cout<<solution(4, 1, {1,2,3,4})<<endl;
    cout<<solution(10, 4, {1,2,3,10})<<endl;
    cout<<solution(10, 3, {1,3,6,7})<<endl;
    cout<<solution(10, 4, {1,2,3,4,8,9,10})<<endl;

    return 0;
}