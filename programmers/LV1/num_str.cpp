#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer;
    string str;

    for(auto it = s.begin(); it != s.end(); ++it){
        if(isdigit(*it)){
            str.push_back(*it);
        }
        else{
            switch(*it){
                case 'z': // zero
                    if(*(it+3) == 'o'){
                        str.push_back('0');
                        it = it + 3;
                        break;
                    }
                case 'o': // one
                    if(*(it+2) == 'e'){
                        str.push_back('1');
                        it = it + 2;
                        break;
                    }
                case 't': // two, three
                    if(*(it+2) == 'o'){
                        str.push_back('2');
                        it = it + 2;
                        break;
                    }
                    else if(*(it+4) == 'e'){
                        str.push_back('3');
                        it = it + 4;
                        break;
                    }
                case 'f': // four, five
                    if(*(it+3) == 'r'){
                        str.push_back('4');
                        it = it + 3;
                        break;
                    }
                    else if(*(it+3) == 'e'){
                        str.push_back('5');
                        it = it + 3;
                        break;
                    } 
                case 's': // six, seven
                    if(*(it+2) == 'x'){
                        str.push_back('6');
                        it = it + 2;
                        break;
                    }
                    else if(*(it+4) == 'n'){
                        str.push_back('7');
                        it = it + 4;
                        break;
                    } 
                case 'e': // eight
                    if(*(it+4) == 't'){
                        str.push_back('8');
                        it = it + 4;
                        break;
                    }
                case 'n': // nine
                    if(*(it+3) == 'e'){
                        str.push_back('9');
                        it = it + 3;
                        break;
                    }
            }
        }
    }
    answer = stoi(str);
    return answer;
}

int main(){
    cout<<solution("one4seveneight")<<endl;
    cout<<solution("23four5six7")<<endl;
    cout<<solution("2three45sixseven")<<endl; 
    cout<<solution("123")<<endl;
    cout<<solution("onetwothreefourfivesixseveneightnine")<<endl;
    

    return 0;
}