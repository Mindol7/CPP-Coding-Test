/* 배열을 오름차순으로 정렬해서 반환하는 문제 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr){
    sort(arr.begin(), arr.end());
    return arr;
}

int main(){
    vector<int> v1 = {1, -5, 2, 4, 3};
    v1 = solution(v1);

    for(auto i : v1){
        cout<<i<<" ";
    }cout<<endl;

    vector<int> v2 = {2, 1, 1, 3, 2, 5, 4};
    v2 = solution(v2);

    for(auto i : v2){
        cout<<i<<" ";
    }cout<<endl;

    vector<int> v3 = {6, 1, 7};
    v3 = solution(v3);

    for(auto i : v3){
        cout<<i<<" ";
    }cout<<endl;



    return 0;
}
