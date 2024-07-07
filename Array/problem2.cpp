#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

bool compare(int a, int b){
    return a > b;
}

vector<int> solution(vector<int> lst){

    sort(lst.begin(), lst.end(), compare); // 먼저 내림차순으로 정렬
    
    lst.erase(unique(lst.begin(), lst.end()), lst.end()); // 중복값 제거한 후 새로운 end 반복자부터 기존의 end 반복자까지 제거
    return lst;
}

int main(){
    vector<int> v1 = {4, 2, 2, 1, 3, 4};

    v1 = solution(v1);

    for(auto i : v1){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int> v2 = {2, 1, 1, 3, 2, 5, 4};
    v2 = solution(v2);

    for(auto i : v2){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}