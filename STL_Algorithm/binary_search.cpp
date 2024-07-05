#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v = {1, 2, 3, 4, 5};

    cout<<binary_search(v.begin(), v.end(), 3)<<endl;
    cout<<binary_search(v.begin(), v.end(), 7)<<endl;

    for(auto i : v){
        if(i == 3){
            cout<<i<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }

    return 0;
}