#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int x=0, y=0;
    int x_size = wallpaper.size();
    int y_size = wallpaper[0].size();
    auto start_point = make_pair(x,y);
    auto temp_point = make_pair(x,y);
    auto end_point = make_pair(x_size-1, y_size-1);
    bool start_flag = false, temp_flag = false, end_flag = false;
    
    /* 시작점 찾기 */
    for(int i = 0; i<x_size; ++i){
        for(int j = 0; j<y_size; ++j){
            if(wallpaper[i][j] == '#'){
                start_flag = true;
                start_point.first = i; start_point.second = j;
                break;
            }
        }
        if(start_flag) break;
    }

    for(int i = 0; i<y_size; ++i){
        for(int j = 0; j<x_size; ++j){
            if(wallpaper[j][i] == '#'){
                temp_point.first = j; temp_point.second = i;
                temp_flag = true;
                break;
            }
        }
        if(temp_flag) break;
    } 

    /* 시작점 정하기 */
    if(start_point.second > temp_point.second){ // 첫번째 파일보다 왼쪽에 있다면
        start_point.second = temp_point.second;
    }
    
    /* 끝점 정하기 */
    for(int i = x_size-1; i>=0; --i){
        for(int j = y_size-1; j>=0; --j){
            if(wallpaper[i][j] == '#'){
                end_flag = true;
                end_point.first = i+1; end_point.second = j+1;
                break;
            }
        }
        if(end_flag) break;
    }
    
    temp_flag = false;
    for(int i = y_size-1; i>=0; --i){
        for(int j = x_size-1; j>=0; --j){
            if(wallpaper[j][i] == '#'){
                temp_flag = true;
                temp_point.first = j+1; temp_point.second = i+1;
                break;
            }
        }
        if(temp_flag) break;
    }
    

    if(end_point.second < temp_point.second){ // 오른쪽에 있다면
        end_point.second = temp_point.second;
    }
    
    answer.push_back(start_point.first);
    answer.push_back(start_point.second);
    
    answer.push_back(end_point.first);
    answer.push_back(end_point.second);

    return answer;
}

int main(){
    vector<int> v1 = solution({".#...", "..#..", "...#."}); // {0, 1, 3, 4}
    
    for(auto i : v1){
        cout<<i<<" ";
    }cout<<endl;

    vector<int> v2 = solution({"..........", ".....#....", "......##..", "...##.....", "....#....."}); // {1, 3, 5, 8}
    
    for(auto i : v2){
        cout<<i<<" ";
    }cout<<endl;

    vector<int> v3 = solution({".##...##.", "#..#.#..#", "#...#...#", ".#.....#.", "..#...#..", "...#.#...", "....#...."}); // {0, 0, 7, 9}
    
    for(auto i : v3){
        cout<<i<<" ";
    }cout<<endl;

    vector<int> v4 = solution({"..", "#."}); // {1, 0, 2, 1}
    
    for(auto i : v4){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}