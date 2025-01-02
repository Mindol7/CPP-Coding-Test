#include <iostream>
using namespace std;

int fib(int n) {
    int n1 = 0;
    int n2 = 1;

    for(int i = 2; i <= n; ++i){
        int num1 = n1;
        int num2 = n2;
        n1 = n2 % 1234567;
        n2 = (num1 + num2)  % 1234567;
        cout << "n1: " << n1 << endl;
        cout << "n2: " << n2 << endl;
    }

    return n2;
}

int main(){
    cout<< fib(90) << endl; // 5
    return 0;
}