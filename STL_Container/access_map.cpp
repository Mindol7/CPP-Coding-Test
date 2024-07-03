#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string, int> studentScores;

    studentScores["Alice"] = 95;
    studentScores["Bob"] = 88;
    studentScores["Charlie"] = 92;

    int score1 = studentScores["Alice"];
    cout<<score1<<endl;

    int score2 = studentScores["rabbit"];
    cout<<score2<<endl;

    auto it = studentScores.find("Charlie");
    if(it != studentScores.end()){
        int score3 = it->second;
        cout<<score3<<endl;
    }

    return 0;
}