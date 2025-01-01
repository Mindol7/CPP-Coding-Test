#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_multimap<string, int> person;
    int i = 1;

    for(string s : participant){
        person.insert(make_pair(s,i));
        i++; 
    }

    unordered_multimap<string, bool> completion_person;
    for(string s : completion){
        completion_person.insert(make_pair(s, true));
    }

    vector<bool> count(participant.size(), false);

    int j = 0, true_count = 0;
    for(string s : participant){
        if(completion_person.count(s) > 1){
            count[j] = false;
            j++;
            continue;
        }
        if(true_count != 0){
            count[j] = false;
            j++;
            continue;
        }
        if(person.count(s) > 1){
            true_count++;
            count[j] = true;
        }
        
        j++;
    }

    unordered_multimap<string, bool> real_person;
    int k = 0;
    for(string s : participant){
        real_person.insert(make_pair(s, count[k]));
        k++;
    }

    for(string s : completion){
        auto it = real_person.find(s);
        if(it != real_person.end() && (!it->second)){
            real_person.erase(it);
        }
    }
    
    for(const auto &pair : real_person){
        answer = pair.first;
    }
    return answer;
}

int main(){
    cout<<solution({"leo", "kiki", "eden"}, {"eden", "kiki"})<<endl;
    cout<<solution({"marina", "josipa", "nikola", "vinko", "filipa"}, {"josipa", "filipa", "marina", "nikola"})<<endl;
    cout<<solution({"mislav", "stanko", "mislav", "ana"}, {"stanko", "ana", "mislav"})<<endl; // mislav
    cout<<solution({"a","b","a","c","d"}, {"a","a","c","d"})<<endl; // b
    cout<<solution({"a","a","b","b","c"}, {"a","a","b","c"})<<endl; // b

    return 0;
}