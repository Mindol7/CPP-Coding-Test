#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int get_cola = 0;
    
    while(n>=a){
        get_cola = (n/a) * b;
        answer += get_cola;
        n = (n%a) + get_cola;
    }
    return answer;
}

int main(){
    cout<<solution(2, 1, 20)<<endl;
    cout<<solution(3, 1, 20)<<endl;
    cout<<solution(4, 1, 20)<<endl;
    cout<<solution(20, 2, 20)<<endl;
    return 0;
}