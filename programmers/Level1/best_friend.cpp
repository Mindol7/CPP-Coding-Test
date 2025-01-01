#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string X, string Y) {
    string answer = "";

    vector<int> x_count(10, 0);
    vector<int> y_count(10, 0);

    for(int i = 0; i < X.size(); ++i){
        switch(X[i]){
            case '0':
                ++x_count[0]; break;
            case '1':
                ++x_count[1]; break;
            case '2':
                ++x_count[2]; break;
            case '3':
                ++x_count[3]; break;
            case '4':
                ++x_count[4]; break;
            case '5':
                ++x_count[5]; break;
            case '6':
                ++x_count[6]; break;
            case '7':
                ++x_count[7]; break;
            case '8':
                ++x_count[8]; break;
            case '9':
                ++x_count[9]; break;
        }
    }

    for(int i = 0; i < Y.size(); ++i){
        switch(Y[i]){
            case '0':
                ++y_count[0]; break;
            case '1':
                ++y_count[1]; break;
            case '2':
                ++y_count[2]; break;
            case '3':
                ++y_count[3]; break;
            case '4':
                ++y_count[4]; break;
            case '5':
                ++y_count[5]; break;
            case '6':
                ++y_count[6]; break;
            case '7':
                ++y_count[7]; break;
            case '8':
                ++y_count[8]; break;
            case '9':
                ++y_count[9]; break;
        }
    }

    map<char, int, greater<char>> num_friend;

    for(int i = 0; i<=9; ++i){
        if(x_count[i] != 0 && y_count[i] != 0){
            if(x_count[i] > y_count[i]){
                num_friend[to_string(i)[0]] = y_count[i];
            }
            else{
                num_friend[to_string(i)[0]] = x_count[i];
            }
        }
    }

    if(num_friend.empty()){
        return "-1";
    }

    if(num_friend.size() == 1 && num_friend['0'] != 0){
        return "0";
    }

    for(const auto & pair : num_friend){
        for(int i = 0; i<pair.second; ++i){
            answer += pair.first;
        }
    }

    return answer;
}

int main(){
    cout<<solution("100", "2345")<<endl; // -1
    cout<<solution("100", "203045")<<endl; // 0
    cout<<solution("100", "123450")<<endl; // 10
    cout<<solution("12321", "42531")<<endl; // 321
    cout<<solution("5525", "1255")<<endl; // 552

    return 0;
}