#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2){
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size()));

    for(int n = 0; n<arr1.size(); ++n){
        for(int k = 0; k<arr2[0].size(); ++k){
            for(int m = 0; m<arr1[0].size(); ++m){
                answer[n][k] += arr1[n][m] * arr2[m][k];
            }
        }
    }  
 
    return answer;
}

int main(){
    vector<vector<int>> v1 = {
        {2,3,2},
        {4,2,4},
        {3,1,4}
    };

    vector<vector<int>> v2 = {
        {5,4,3},
        {2,4,1},
        {3,1,1}
    };
    vector<vector<int>> v3(v1.size(), vector<int> (v2[0].size()));
    v3 = solution(v1, v2);
    for(int i = 0; i<v3.size(); ++i){
        for(int j = 0; j<v3[0].size(); ++j){
            cout<<v3[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}