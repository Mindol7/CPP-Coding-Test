#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums){
    int max_mon = nums.size()/2;

    set<int> s(nums.begin(), nums.end());

    if(s.size() >= max_mon){
        return max_mon;
    }
    else{ // 작을때
        return s.size();
    }
}

int main(){
    cout<<solution({3,1,2,3})<<endl;
    cout<<solution({3,3,3,2,2,4})<<endl;
    cout<<solution({3,3,3,2,2,2})<<endl;
    cout<<solution({1,2,3,4,5,6})<<endl;
    return 0;
}