#include <iostream>
#include <ctime>
#include <set>
using namespace std;
time_t t;
time_t t2;
int solution(int size_arr, set<int> v, int x){
    int answer = 0;
    for(auto it = v.begin(); it != v.end(); ++it){
        if(v.find(x - *it) != v.end()){
            answer++;
        }
    }


    return answer/2;
}

int main(){
    int size_arr = 9;
    set<int> v1;
    int x;
    int a;
    cin>>size_arr;
    
    for(int i = 0; i < size_arr; ++i){
        cin>>a;
        v1.insert(a);
    }
    cin>>x;
    t = time(nullptr);
    cout<<solution(size_arr, v1, x)<<endl;
    t2 = time(nullptr);
    cout<<t2<<endl;
    return 0;
}