#include <iostream>

using namespace std;

int main(){
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[5] = {1, 2}; // 나머지 부분은 0이됨
    int arr3[5] = {}; // 원소를 0으로 초기화한 배열

    int arr4[5]; // 쓰레기값으로 초기화된거

    // int arr5[];, 이거는 잘못된 방법임 0을 준것도 아니고 쓰레기값을 준건데 배열 크기도 명시안했음

    return 0;
}
