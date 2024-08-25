#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;

    int idx;
    int sort_idx;

    if(ext == "code") idx = 0;
    else if(ext == "date") idx = 1;
    else if(ext == "maximum") idx = 2;
    else idx = 3;

    if(sort_by == "code") sort_idx = 0;
    else if(sort_by == "date") sort_idx = 1;
    else if(sort_by == "maximum") sort_idx = 2;
    else sort_idx = 3;

    for(auto data_element : data){
        if(data_element[idx] < val_ext){
            answer.push_back(data_element);
        }
    }

    sort(answer.begin(), answer.end(), [sort_idx](const vector<int> &a, const vector<int> &b){
        return a[sort_idx] < b[sort_idx] ;
    });

    return answer;
}

int main(){
    vector<vector<int>> v1 = solution({{1, 20300104, 100 ,80}, {2, 20300804, 847, 37}, {3, 20300401, 10, 8}}, "date", 20300501, "remain");
    
    for(auto i : v1){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }cout<<endl;

    return 0;
}