#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const int &a, const int &b){
    if(a < b){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    vector<int> v = {3, 1, 2};
    // sort(v.begin(), v.end()); // 첫 번째 정렬 방법 (오름차순 정렬)
    // sort(v.rbegin(), v.rend()); // 두 번째 정렬 방법 (내림차순 정렬)

    sort(v.begin(), v.end(), compare); // 세 번째 정렬 방법 (사용자 정의 함수를 통한 정렬)

    do{
        for(auto i : v){
            cout<<i<<" ";
        }
        cout<<endl;
    }while(next_permutation(v.begin(), v.end()));

    return 0;
}