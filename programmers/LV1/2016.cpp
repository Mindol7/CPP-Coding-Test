#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    map<int, int> calander = {{1,31}, {2,29}, {3,31}, {4,30}, {5,31}, {6,30},
                              {7,31}, {8,31}, {9,30}, {10,31}, {11,30}, {12,31}};

    vector<string> day = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    int total_day = 0;
    for(int i = 1; i<a; ++i){
        total_day += calander[i];
    }
    total_day += b;
    
    answer = day[total_day % 7];

    return answer;
}

int main(){
    cout<<solution(5,24)<<endl;
    cout<<solution(2,29)<<endl;
    cout<<solution(12,31)<<endl;
    cout<<solution(1,7)<<endl;
}