#include <iostream>
#include <set>

using namespace std;

int main(){
    set<int> numbers = {1, 2, 3, 4, 5};
    int targets[] = {3, 8};

    for(int target : targets){
        auto it = numbers.find(target);

        if(it != numbers.end()){
            cout<<"Find : "<<*it<<endl;
        }
        else{
            cout<<"Not Found"<<endl;
        }
    }

    return 0;
}