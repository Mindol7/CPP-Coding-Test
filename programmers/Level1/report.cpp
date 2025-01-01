#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    unordered_map<string, vector<string>> report_map;    
    unordered_map<string, int> report_count;
    unordered_set<string> filter_report;

    for(const auto &str: report){ // 중복 제거
        filter_report.insert(str);
    }

    string report_person;

    for(auto str: id_list){
        report_map[str];
        report_count[str] = 0;
    }

    for(auto &str: filter_report){
        int count = 0;
        istringstream stream(str);
        string tmp;
        while(getline(stream, tmp, ' ')){
            if(count == 1) {
                report_map[report_person].push_back(tmp); 
                report_count[tmp]++;
            }
            else{
                report_person = tmp;
                count++;
            }
        }
    }

    for(auto str: id_list){
        if(report_count[str] >= k){
            int i = 0;
            for(auto key: id_list){
                for(auto value: report_map[key]){
                    if(value == str){
                        ++answer[i];
                    }
                }
                ++i;
            }
        }
    }
    return answer;
}

int main(){
    vector<int> v1 = solution({"muzi", "frodo", "apeach", "neo"}, {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"}, 2);

    for(auto i : v1){ // 2,1,1,0
        cout<<i<<" ";
    }cout<<endl;

    vector<int> v2 = solution({"con", "ryan"}, {"ryan con", "ryan con", "ryan con", "ryan con"}, 3);

    for(auto i : v2){ // 0,0
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}