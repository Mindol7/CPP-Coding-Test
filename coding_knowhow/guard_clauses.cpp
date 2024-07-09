#include <iostream>
#include <vector>

using namespace std;

double get_avg(const vector<int> &arr, int N){
    if(arr.empty()){ // Guard Clauses
        return -1;
    }

    if(N == 0){
        return -1;
    }

    int sum = 0;
    for(int num : arr){
        sum += num;
    }

    return sum / N;
}

int main(){
    vector<int> v = {100, 300, 320, 283, 509};
    cout<<get_avg(v, 5)<<endl;
    return 0;
}
