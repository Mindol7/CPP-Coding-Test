#include <iostream>
#include <map>

using namespace std;

int main(){
    map<int, string> myMap;

    myMap.insert(make_pair(1, "Apple"));
    myMap.insert({2, "Banana"});
    myMap[3] = "Cherry";

    for(const auto &pair : myMap){
        cout<<pair.first<<": "<<pair.second<<endl;
    }

    myMap.erase(2);

    for(const auto &pair : myMap){
        cout<<pair.first<<": "<<pair.second<<endl;
    }

    auto it = myMap.find(3);
    if(it != myMap.end()){
        cout<<it->first<<": "<<it->second<<endl;
        myMap.erase(it);
        cout<<it->first<<": "<<it->second<<endl; // map에서 삭제했는데도 출력됨, 흠 ... it에 할당되는건 복사된 주소의 값인가? -> 이러면 말됨
    }

    for(const auto &pair : myMap){
        cout<<pair.first<<": "<<pair.second<<endl;
    }

    return 0;
}