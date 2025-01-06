#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for(int i = 1; i <= yellow; ++i){ // i는 가로, 몫은 세로
        int height = yellow / i;
        int check = yellow % i;
        if (i >= height && check == 0 && (i + 2 +height) * 2 == brown){
            answer.push_back(i+2);
            answer.push_back(height+2);
            return answer;
        }
    }
}

int main(){
    vector<int> v1 = solution(10, 2); // 4,3
    vector<int> v2 = solution(8, 1); // 3,3
    vector<int> v3 = solution(24, 24); // 8,6

    for(auto i : v1){
        cout << i << " ";
    }cout<<endl;
    
    for(auto i : v2){
        cout << i << " ";
    }cout<<endl;
    
    for(auto i : v3){
        cout << i << " ";
    }cout<<endl;

    return 0;
}