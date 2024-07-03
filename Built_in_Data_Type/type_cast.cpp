#include <iostream>
using namespace std;

int main(){
    int i = 65;
    float f = 5.2f;

    double d = i + f; // 암시적 형변환 -> 메모리 크기가 큰 쪽으로 형 변환이됨
    cout<<d<<endl;

    /* 명시적 형 변환 */
    cout<<static_cast<int>(d)<<endl;
    cout<<static_cast<char>(i)<<endl;

    cout<<static_cast<char>(d)<<endl;

    return 0;
}