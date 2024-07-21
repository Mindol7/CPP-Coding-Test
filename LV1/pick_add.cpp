#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int sum;

    for(int i = 0; i<numbers.size(); ++i){
        for(int j = i+1; j<numbers.size(); ++j){
            sum = numbers[i] + numbers[j];
            auto it = find(answer.begin(), answer.end(), sum);

            if(it == answer.end()){
                answer.push_back(sum);
            }
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}

int main(){
    vector<int> v1 = solution({2,1,3,4,1});
    vector<int> v2 = solution({5,0,2,7});

    for(auto i : v1){
        cout<<i<<" ";
    }cout<<endl;

    for(auto i : v2){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}