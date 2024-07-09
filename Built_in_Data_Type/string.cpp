#include <iostream>
#include <string>
using namespace std;

int main(){
    string str1;
    string str2 = "Hello, World!";
    string str3(str2); // 문자열 복사
    string str4(str2, 0, 5); // Hello까지만 복사
    string str5(10, '*'); // 반복된 문자로 초기화

    return 0;
}