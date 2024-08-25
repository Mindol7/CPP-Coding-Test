#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> hambuger = {1, 2, 3, 1};

    for(int i = 0; !((i+3) >= ingredient.size()); ++i){
        if(ingredient.size() <= 3){
            return answer;
        }

        if(!((i+3) >= ingredient.size())){
            if(ingredient[i] != hambuger[0]){
                continue;
            }
            if(ingredient[i] == hambuger[0] && ingredient[i+1] == hambuger[1]
             && ingredient[i+2] == hambuger[2] && ingredient[i+3] == hambuger[3]){
                answer++;
                cout<<"IDX: "<<i<<endl;
                ingredient.erase(ingredient.begin()+(i), ingredient.begin()+(i+4));

                if(i==0){
                    i = -1;
                }

                if(i>0){
                    if(ingredient[i-1] == hambuger[0] && i-1 < 0) i = -1;
                    else if(ingredient[i-2] == hambuger[0] && i-2 < 0) i = -1;
                    else if(ingredient[i-3] == hambuger[0] && i-3 < 0) i = -1;
                    else if(ingredient[i-4] == hambuger[0] && i-4 < 0) i = -1;
                    else if(ingredient[i-1] == hambuger[0] && i-1 >= 0){
                        i-=2;
                    }
                    else if(ingredient[i-2] == hambuger[0] && i-2 >= 0){
                        i-=3;
                    }
                    else if(ingredient[i-3] == hambuger[0] && i-3 >= 0){
                        i-=4;
                    }
                    else if(ingredient[i-4] == hambuger[0] && i-4 >= 0){
                        i-=5;
                    }
                }
             }

        }
    }
    return answer;
 }

int main(){
    cout<<solution({2, 1, 1, 2, 3, 1, 2, 3, 1})<<endl; // 2
    cout<<solution({1, 3, 2, 1, 2, 1, 3 ,1, 2})<<endl; // 0
    cout<<solution({1, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1})<<endl; // 3
    cout<<solution({1,2,3,1, 1,2,3,1, 1,2,3,1, 1,2,3,1})<<endl; // 4
    cout<<solution({1, 1, 2, 3, 3, 1, 2, 3, 1, 2, 3, 1})<<endl; // 1
    cout<<solution({1, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 1, 1})<<endl; // 2
    cout<<solution({1, 2, 3, 2, 1, 2, 3, 1, 1})<<endl; // 1
    cout<<solution({2, 1, 1, 2, 1, 2, 1, 2, 3, 1, 3, 1, 3, 1, 2, 3, 1})<<endl; // 4
    cout<<solution({1,2,1,2,3,1,3,1})<<endl; // 2
    cout<<solution({1,2,3,1,1,2,3,1,1})<<endl; // 2
    cout<<solution({1,2,3,2,1})<<endl; // 0
    cout<<solution({1, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1})<<endl; // 3
    cout<<solution({1, 2, 3, 1, 2, 3, 1, 1, 1, 1, 2, 3, 1, 2, 3, 1, 1, 1, 1, 1, 1, 2, 3, 3, 1, 2, 3, 1, 3, 3, 3, 2, 1, 2, 3, 1})<<endl; // 5
    return 0;
}