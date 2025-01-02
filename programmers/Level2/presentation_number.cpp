#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int digit = 0;

    for(int i = 0; i < n; i++){
        digit += i;
        int share = n - digit;
        int div = i + 1;

        if(share % div == 0 && share >= div) answer++;
    }

    return answer;
}

int main(){
    cout << solution(15) << endl; // 4

    return 0;
}