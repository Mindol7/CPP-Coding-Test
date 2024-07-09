#include <iostream>
#include <set>
using namespace std;

int main(){
    set<int> s = {1, 3, 2, 1, 5};

    for(auto i : s){
        cout<<i<<" ";
    }
    cout<<endl;

    s.insert(4);

    for(auto it = s.begin(); it != s.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;

    s.erase(2);
    for(auto i : s){
        cout<<i<<" ";
    }
    cout<<endl;
    
    auto it = s.find(4);

    if(it != s.end()){
        cout<<"Find : "<<*it<<endl;
    }


    return 0;
}
