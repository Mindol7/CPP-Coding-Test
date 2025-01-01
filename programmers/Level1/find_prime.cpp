#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> vec(n + 1, true); // 크기를 n+1로 설정

    vec[0] = vec[1] = false; // 0과 1은 소수가 아님

    for (int i = 2; i * i <= n; ++i) {
        if (vec[i]) {
            for (int j = i * i; j <= n; j += i) {
                vec[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (vec[i]) {
            answer++;
        }
    }

    return answer;
}

int main() {
    cout << solution(10) << endl; // 예상 출력: 4 (2, 3, 5, 7)
    cout << solution(5) << endl;  // 예상 출력: 3 (2, 3, 5)

    return 0;
}
