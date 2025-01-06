#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());

    int left = 0;
    int right = people.size() - 1;

    while(left <= right){
        if(people[left] + people[right] <= limit){
            left++;
        }
        right--;
        answer++;       
    }
    
    return answer;
}

int main(){
    cout << solution({70,50,80,50}, 100) << endl; // 3
    cout << solution({70,80,50}, 100) << endl; // 3 
    return 0;
}