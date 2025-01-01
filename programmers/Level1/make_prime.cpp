#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int nums_size = nums.size();
    int prime_ = 0, prime_count = 0;
    
    for(int i = 0; i<nums_size-2; ++i){
        for(int j = i+1; j<nums_size-1; ++j){
            for(int k = j+1; k<nums_size; ++k){
                prime_ = nums[i]+nums[j]+nums[k];

                for(int m = 1; m<=prime_; ++m){
                    if(prime_%m == 0){
                        prime_count++;
                    }
                }
                if(prime_count == 2){
                    answer++;
                }
                prime_count = 0;
            }
        }
    }
    return answer;
}

int main(){
    cout<<solution({1,2,3,4})<<endl;
    cout<<solution({1,2,7,6,4})<<endl;

    return 0;
}