#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<string> days = {"월", "화", "수", "목", "금", "토", "일"};

    for(int i = 0; i <= 30; i++){
        cout<<days[i % days.size()]<<endl;
    }

    return 0;
}