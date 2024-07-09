#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
    unordered_set<int> myUnorderedSet;

    /* Insert -> 맨 앞에 추가 */
    myUnorderedSet.insert(3);
    myUnorderedSet.insert(1);
    myUnorderedSet.insert(4);
    myUnorderedSet.insert(2);

    for(int num : myUnorderedSet){
        cout<<num<<" ";
    }
    cout<<endl;

    return 0;
}
