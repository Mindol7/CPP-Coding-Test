#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);

    stack<int> arr1_stack;
    stack<int> arr2_stack;

    vector<vector<int>> temp;

    for(int i = 0; i<n; ++i){
        while(true){
            if(arr1[i] / 2 == 0){
                arr1_stack.push(arr1[i]%2);
                break;
            }
            else{
                arr1_stack.push(arr1[i]%2);
                arr1[i] = arr1[i] / 2;
            }
        }

        while(true){
            if(arr2[i] / 2 == 0){
                arr2_stack.push(arr2[i]%2);
                break;
            }
            else{
                arr2_stack.push(arr2[i]%2);
                arr2[i] = arr2[i] / 2;
            }
        }

        if(arr1_stack.size() != n){ // 0001 -> 00010
            for(int j = arr1_stack.size(); j<n; ++j){
                arr1_stack.push(0);
            }
        }
        if(arr2_stack.size() != n){ // 0001 -> 00010
            for(int j = arr2_stack.size(); j<n; ++j){
                arr2_stack.push(0);
            }
        }

        

        while(!arr1_stack.empty() && !arr2_stack.empty()){
            if(arr1_stack.top() | arr2_stack.top()){
                answer[i].push_back('#');
            }
            else{
                answer[i].push_back(' ');
            }
            arr1_stack.pop();
            arr2_stack.pop();
        }

       
    }

    return answer;
}

int main(){
    vector<string> str1 = solution(5, {9,20,28,18,11}, {30,1,21,17,28});
    vector<string> str2 = solution(6, {46,33,33,22,31,50}, {27,56,19,14,14,10});

    for(auto i : str1){
        cout<<i<<" ";
    }cout<<endl;

    for(auto i : str2){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}