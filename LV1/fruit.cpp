#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> apple_box;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    if(score.empty() || m> score.size()){    
        return answer;
    }
    sort(score.rbegin(), score.rend());

    for(int i = 0; i<m; ++i){   
        apple_box.push_back(score[i]);
    }
    
    score.erase(score.begin(), score.begin() + m);
    
    
    answer += (*min_element(apple_box.begin(), apple_box.end())) * m + solution(k,m,score);
    apple_box.clear();
    
    return answer;
}

int main(){
    cout<<solution(3, 4, {1,2,3,1,2,3,1})<<endl;
    cout<<solution(4, 3, {4,1,2,2,4,4,4,4,1,2,4,2})<<endl;

    return 0;
}