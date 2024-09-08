#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    bool flag = true;

    for(int i = 0; i<new_id.size(); ++i){
        if(new_id[i] >= 0x41 && new_id[i] <= 0x5a) new_id[i] = new_id[i] + 0x20;
    }
    cout<<"First Step : "<<new_id<<endl;

    for(int i = 0; i<new_id.size(); ++i){
        if((new_id[i] >= 0x21 && new_id[i] <= 0x2f) || (new_id[i] >= 0x3a && new_id[i] <= 0x40)
           || (new_id[i] >= 0x5b && new_id[i] <= 0x60) || (new_id[i] >= 0x7b && new_id[i] <= 0x7e)){
            if(new_id[i] != 0x2e && new_id[i] != 0x5f && new_id[i] != 0x2d){
                cout<<"Erase Data : "<<new_id[i]<<", idx: "<<i<<endl;
                new_id.erase(i--, 1); // i번째 idx에서 1개 제거
            }
           }
    }
    cout<<"Second Step : "<<new_id<<endl;
    // .의 연속 여부 확인
        for(int i = 0; i<new_id.size(); ++i){
            if(new_id[i] == 0x2e && new_id[i+1] == 0x2e){
                // . 치환
                cout<<"Erase Data : "<<new_id[i]<<", idx: "<<i<<endl;
                new_id.erase(i--+1, 1);
                
            }
            
        }
    
    cout<<"3 Step : "<<new_id<<endl;
    // .의 처음 끝 존재하는 지 확인

    if(new_id[0] == 0x2e){
        new_id.erase(0, 1);
    }
    if(new_id[new_id.size()-1] == 0x2e){
        new_id.erase(new_id.size()-1, 1);
    }
    cout<<"4 Step : "<<new_id<<endl;
    
    // 빈 문자열일때 a 대입
    if(new_id.empty()){
        new_id.push_back('a');
    }
    cout<<"5 Step : "<<new_id<<endl;
    
    // 16개 이상일 경우 다 제거
    if(new_id.size() >= 16){
        new_id.erase(15);

        if(new_id[new_id.size()-1] == 0x2e) new_id.erase(new_id.size()-1, 1);
    }
    cout<<"6 Step : "<<new_id<<endl;
    
    // 2자 이하면 3이 될때까지 반복

    if(new_id.size() <= 2){
        while(true){
            if(new_id.size() == 3) break;

            new_id.push_back(new_id[new_id.size()-1]);
        }
    }
    cout<<"7 Step : "<<new_id<<endl;
    
    answer = new_id;
    return answer;
}

int main(){
    cout<<solution("...!@BaT#*..y.abcdefghijklm")<<endl; // "bat.y.abcdefghi"
    // cout<<solution("z-+.^.")<<endl; // "z--"
    // cout<<solution("=.=")<<endl; // "aaa"
    // cout<<solution("123_.def")<<endl; // "123_.def"
    // cout<<solution("abcdefghijklmn.p")<<endl; // "abcdefghijklmn"
    // cout<<solution(".......")<<endl;
    return 0;
}