#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

int solution(int n) {
    int num = bitset<20>(n).count();

    while(bitset<20>(++n).count() != num);
    return n;
}

int main(){
    cout << solution(78) << endl; // 83
    cout << solution(15) << endl; // 23
    return 0;
}