#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v1 = {5,3,2,1,7};
    int min = v1[0];
    for(auto it = v1.begin(); it != v1.end(); ++it){
        if(*it < min){
            min = *it;
        }
    }

    cout<<min<<endl;

    return 0;
}