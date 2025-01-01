#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//
vector<int> solution(string s) {
    vector<int> answer;
    int remove_zero_num = 0;
    int convert_num = 0;

    while(true){
        if(s == "1"){
            answer.push_back(convert_num);
            answer.push_back(remove_zero_num);
            return answer;
        }
        string str = "";
        remove_zero_num += count(s.begin(), s.end(), '0');

        s.erase(remove(s.begin(), s.end(), '0'), s.end()); // 0 제거 -> 0제거 한 것처럼 모두 밀고, 새로운 끝 위치 제공
        int tmp = s.length();
        
        while(true){
            if(tmp / 2 == 0){
                if(tmp % 2 == 0) str.insert(0, "0");
                else str.insert(0, "1");
                s = str;
                break;
            }
            
            if(tmp % 2 == 0) str.insert(0, "0");
            else str.insert(0, "1");
            tmp /= 2;
        }

        convert_num++;
    }
}

int main(){
    vector<int> v1 = solution("110010101001"); // 3,8
    vector<int> v2 = solution("01110"); // 3,3
    vector<int> v3 = solution("1111111"); // 4,1

    for(auto i : v1){
        cout<<i<<",";
    }
    cout<<endl;
    
    for(auto i : v2){
       cout<<i<<",";
    }
    cout<<endl;
    
    for(auto i : v3){
        cout<<i<<",";
    }cout<<endl;

    return 0;
}