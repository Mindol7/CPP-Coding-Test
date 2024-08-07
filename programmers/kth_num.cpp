#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    int i = 0;
    int start = 0, end = 0, idx = 0;
    while(i<commands.size()){
        int pop = 0;
        start = commands[i][0]; end = commands[i][1]; idx = commands[i][2];
        for(int i = start-1; i<=end-1; ++i){
            temp.push_back(array[i]);
        }

        sort(temp.begin(), temp.end());
        answer.push_back(temp[idx-1]);

        while(pop < temp.size()){
            temp.pop_back();
        }
        i++;
    }
    return answer;
}

int main(){
    vector<vector<int>> v = {{2,5,3}, {4,4,1}, {1,7,3}};
    vector<int> v2 = solution({1,5,2,6,3,7,4}, v);

    for(auto i : v2){
        cout<<i<<" ";
    }cout<<endl;
    
    return 0;
}