#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    int number = left;

    while(number <= right){
        vector<int> v;
        for(int i = 1; i <= number; ++i){
            if(number % i == 0){
                v.push_back(i);
            }           
        }

        if(v.size() % 2 == 0){
            answer += number;
        }
        else{
            answer -= number;
        }

        ++number;
    }    

    return answer;
}