#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v = {1, 3, 3, 2, 2, 3, 3, 4, 5, 5, 5, 5};

    auto newEnd = unique(v.begin(), v.end());

    for(auto it = v.begin(); it != newEnd; ++it){
        cout<<*it<<" ";
    }
    cout<<endl;

    cout<<v.size()<<endl;

    for(auto it = v.begin(); it != v.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;


    return 0;
}