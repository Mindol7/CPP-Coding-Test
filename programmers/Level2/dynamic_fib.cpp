#include <iostream>
#include <vector>

using namespace std;

vector<int> memo(100, -1);

int fib(int n){
    if (n <= 1) return n; // 이미 전제되는 값 0, 1
    if (memo[n] != -1) return memo[n]; // 계산 되어 있으면 그거 줌
    return memo[n] = fib(n-1) + fib(n-2); // 계산 되어 있지 않으면 계산
}

int main(){
    cout << fib(10) << endl; // 55
    return 0;
}