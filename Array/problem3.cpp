#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int &a, int &b){
    return a < b;
}

vector<int> solution(vector<int> numbers){
    vector<int> sum = {};
    for(auto it = numbers.begin(); it != numbers.end(); ++it){ 
        for(auto it_ = numbers.begin(); it_ != numbers.end(); ++it_){
            if(it != it_){
                sum.push_back(*it + *it_);
            }
        }
    }
    

    sort(sum.begin(), sum.end(), compare); // 오름차순 정렬
    sum.erase(unique(sum.begin(), sum.end()), sum.end()); // 중복값 제거 후 반환

    return sum;
}


int main(){
    vector<int> v1 = {2, 1, 3, 4, 1};
    v1 = solution(v1);

    for(auto i : v1){
        cout<<i<<" ";
    }
    cout<<endl;


    vector<int> v2 = {5, 0, 2, 7};
    v2 = solution(v2);

    for(auto i : v2){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}
