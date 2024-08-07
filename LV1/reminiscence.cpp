#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    int score = 0;
    for(int i = 0; i<photo.size(); ++i){
        for(int j = 0; j<photo[i].size(); ++j){
            auto it = find(name.begin(), name.end(), photo[i][j]);
            if(it != name.end()){ 
                score += yearning[distance(name.begin(), it)];
            }    
        }
        answer.push_back(score);
        score = 0;
    }

    return answer;
}

int main(){
    vector<int> v1 = solution({"may", "kein", "kain", "radi"}, {5,10,1,3}, {{"may", "kein", "kain", "radi"}, {"may", "kein", "brin", "deny"}, {"kon", "kain", "may", "coni"}});
    vector<int> v2 = solution({"kali", "mari", "don"}, {11,1,55}, {{"kali", "mari", "don"}, {"pony", "tom", "teddy"}, {"con", "mona", "don"}});
    vector<int> v3 = solution({"may", "kein", "kain", "radi"}, {5,10,1,3}, {{"may"}, { "kein", "deny", "may"}, {"kon", "coni"}});

    for(auto i : v1){
        cout<<i<<" ";
    }cout<<endl;
    
    for(auto i : v2){
        cout<<i<<" ";
    }cout<<endl;

    for(auto i : v3){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}