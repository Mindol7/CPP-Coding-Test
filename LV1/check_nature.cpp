#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> score_table;    
    int idx = 0;
    for(auto i : survey){ 
        if(choices[idx] > 4) score_table[i[1]] += choices[idx] - 4;
        else if(choices[idx] < 4) score_table[i[0]] += 4 - choices[idx];
        idx++;
    }

    if(score_table['R'] >= score_table['T']) answer += 'R';
    else answer +='T';
    
    if(score_table['C'] >= score_table['F']) answer += 'C';
    else answer +='F';
    
    if(score_table['J'] >= score_table['M']) answer += 'J';
    else answer +='M';
    
    if(score_table['A'] >= score_table['N']) answer += 'A';
    else answer +='N';
    

    return answer;
}

int main(){
    cout<<solution({"AN", "CF", "MJ", "RT", "NA"}, {5, 3, 2, 7, 5})<<endl;
    cout<<solution({"TR", "RT", "TR"}, {7, 1, 3})<<endl;

    return 0;
}