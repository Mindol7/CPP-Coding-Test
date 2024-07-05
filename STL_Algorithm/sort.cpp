#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v = {4, 2, 5, 3, 1};

    sort(v.begin(), v.end());

    for(auto i : v){
        cout<<i<<" ";
    }
    cout<<endl;

    for(auto it = v.begin(); it != v.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;

    /* 역방향 반복자를 통한 내림차순 정렬 */
    sort(v.rbegin(), v.rend());

    for(auto i : v){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}