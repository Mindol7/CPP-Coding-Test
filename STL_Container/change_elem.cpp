#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> vec = {1, 2, 3, 4, 5};

    vec[2] = 10;

    for(auto i : vec){
        cout<<i<<" ";
    }
    cout<<endl;

    for(auto it = vec.begin(); it != vec.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}
