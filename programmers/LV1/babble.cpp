#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    bool flag = false;

    for(int i = 0; i<babbling.size(); ++i){
        int idx = 0;
        bool aya_flag = false, ye_flag = false, woo_flag = false, ma_flag = false;
        for(int j = 0; j<babbling[i].size(); j = idx){    
            string s = "";
            if(babbling[i][j] == 'a' && aya_flag == false){
                s = babbling[i].substr(j,3);
                if(s != "aya"){
                    flag = false;
                    break;
                }
                aya_flag = true, woo_flag = false, ye_flag = false, ma_flag = false;
                flag = true;
                idx = idx + s.size();
            }
            else if(babbling[i][j] == 'y' && ye_flag == false){
                s = babbling[i].substr(j,2);
                if(s != "ye"){
                    flag = false;
                    break;
                }
                ye_flag = true, aya_flag = false, woo_flag = false, ma_flag = false;
                flag = true;
                idx = idx + s.size();
            }
            else if(babbling[i][j] == 'w' && woo_flag == false){
                s = babbling[i].substr(j,3);
                if(s != "woo"){
                    flag = false;
                    break;
                }
                woo_flag = true, aya_flag = false, ma_flag = false, ye_flag = false;
                flag = true;
                idx = idx + s.size();
            }
            else if(babbling[i][j] == 'm' && ma_flag == false){
                s = babbling[i].substr(j,2);
                if(s != "ma"){
                    flag = false;
                    break;
                }
                ma_flag = true, woo_flag = false, aya_flag = false, ye_flag = false;
                flag = true;
                idx = idx + s.size();
            }
            else{
                flag = false;
                break;
            }     
        }

        if(flag == true){
            answer++;
        }
    }
    return answer;
}

int main(){
    cout<<solution({"aya", "yee", "u", "maa"})<<endl; // Print 1
    cout<<solution({"ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"})<<endl; // Print 2
    cout<<solution({"ayayeayaaya"})<<endl;
    cout<<solution({"maya"})<<endl;
    return 0;
}