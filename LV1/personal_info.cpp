#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    istringstream today_stream(today);
    string temp;
    int today_year, today_month, today_day;
    int today_count = 0;
    while(getline(today_stream, temp, '.')){
        if(today_count == 0){
            today_year = stoi(temp);
            ++today_count;
        } 
        else if(today_count == 1){
            today_month = stoi(temp);
            ++today_count;
        }
        else{
            today_day = stoi(temp);
            break;
        }
    }

    vector<pair<string, int>> terms_list;
    string tok; int terms_count = 0; int idx = 0;
    int terms_size;

    for(auto terms_tok : terms){
        istringstream terms_stream(terms_tok);
        terms_list.emplace_back(); 
        while(getline(terms_stream, tok, ' ')){
            if(terms_count == 0){
                terms_list[idx].first = tok;
                ++terms_count;
            }
            else if(terms_count == 1){
                terms_list[idx].second = stoi(tok);
            }
        }
        terms_count = 0;
        idx++;
    }

    vector<int> policy_year; vector<int> policy_month; vector<int> policy_day;
    vector<char> policy_terms;
    string policy_tok;
    int policy_count = 0;

    for(auto &i : privacies){
        policy_terms.push_back(i.back());
        i.erase(i.end()-2, i.end()); // "2021.05.02"
        istringstream policy_stream(i);
        while(getline(policy_stream, policy_tok, '.')){
            if(policy_count == 0){
                policy_year.push_back(stoi(policy_tok));
                ++policy_count;
            }
            else if(policy_count == 1){
                policy_month.push_back(stoi(policy_tok));
                ++policy_count;
            }
            else{
                policy_day.push_back(stoi(policy_tok));
                policy_count = 0;
                break;
            }
        }
    }
    vector<bool> flag(policy_terms.size(), false);

    for(int i = 0; i<policy_terms.size(); ++i){
        for(int j = 0; j<terms_list.size(); ++j){
            for(char c : terms_list[j].first){
                if(policy_terms[i] == c){
                // 비교해야함
                    policy_month[i] += terms_list[j].second;
                    if(policy_month[i] > 12){
                        if(policy_month[i] % 12 == 0){    
                            policy_year[i] += policy_month[i] / 12 - 1;
                            policy_month[i] = policy_month[i] % 12 + 12;
                        }
                        else{
                            policy_year[i] += policy_month[i] / 12;
                            policy_month[i] = policy_month[i] % 12;
                        }
                    }
                    if(policy_year[i] < today_year){
                        flag[i] = true;
                    }
                    else if(policy_year[i] == today_year && policy_month[i] < today_month){
                        flag[i] = true;
                    }
                    else if(policy_year[i] == today_year && policy_month[i] == today_month && policy_day[i] < today_day){
                        flag[i] = true;
                    }
                    else if(policy_year[i] == today_year && policy_month[i] == today_month && policy_day[i] == today_day){
                        flag[i] = true;
                    }                
                }
            }
            
        }
    }

    for(int i = 0; i<flag.size(); ++i){
        if(flag[i]){
            answer.push_back(i+1);
        }
    }
    return answer;
}

int main(){
    vector<int> v1 = solution("2022.05.19", {"A 6", "B 12", "C 3"}, {"2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"});

    for(auto i : v1){ // 1,3
        cout<<i<<" ";
    }cout<<endl;

    vector<int> v2 = solution("2020.01.01", {"Z 3", "D 5"}, {"2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"});
    for(auto i : v2){ // 1,4,5
        cout<<i<<" ";
    }cout<<endl;

    vector<int> v3 = solution("2009.12.28", {"A 13"}, {"2008.11.03 A"});
    for(auto i : v3){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}