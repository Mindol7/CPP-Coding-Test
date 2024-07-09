#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v = {2, 3, 4, 5};

    for(auto i : v){
        cout<<i<<" ";
    }
    cout<<endl;

    for(auto it = v.begin(); it != v.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;

    v.insert(v.begin(), 1);

    for(auto i : v){
        cout<<i<<" ";
    }
    cout<<endl;

    for(auto it = v.begin(); it != v.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;

    v.erase(v.begin());

    for(auto i : v){
        cout<<i<<" ";
    }
    cout<<endl;

    for(auto it = v.begin(); it != v.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}
