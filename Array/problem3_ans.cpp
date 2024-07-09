#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers){
    set<int> sum;

    for(int i = 0; i < numbers.size(); ++i){
        for(int j = i + 1; j < numbers.size(); ++j){
            sum.insert(numbers[i] + numbers[j]);
        }
    }

    vector<int> answer(sum.begin(), sum.end());
    return answer;
}

int main(){
    vector<int> v1 = {5, 0, 2, 7};
    v1 = solution(v1);

    vector<int> v2 = {2, 0, 1, 3, 4};
    v2 = solution(v2);

    for(auto i : v1){
        cout<<i<<" ";
    }
    cout<<endl;

    for(auto j : v2){
        cout<<j<<" ";
    }
    cout<<endl;
    
    return 0;
}