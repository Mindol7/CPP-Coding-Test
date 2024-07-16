#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Point{
    int x = 0;
    int y = 0;
};

int solution(string dirs){
    int answer = 0;
    int path_len = 0;
    int dup_len = 0;
    vector<Point> all_path(dirs.size()+1, {0,0});
    vector<Point> my_path(dirs.size()+1, {0,0});

    path_len = dirs.size();
    all_path[0] = {0,0};
    for(int i = 1; i <= dirs.size(); ++i){
        switch(dirs[i-1]){
            case 'U':
                cout<<"U";
                if(all_path[i-1].y + 1 <= 5){    
                    all_path[i].x = all_path[i-1].x;
                    all_path[i].y = all_path[i-1].y + 1;
                }
                else{
                    cout<<"Range over U"<<endl;
                    all_path[i].x = all_path[i-1].x;
                    all_path[i].y = all_path[i-1].y;
                }
                break;

            case 'D':
                cout<<"D";
                if(all_path[i-1].y - 1 >= -5){    
                    all_path[i].x = all_path[i-1].x;
                    all_path[i].y = all_path[i-1].y - 1;
                }
                else{
                    cout<<"Range over D"<<endl;
                    all_path[i].x = all_path[i-1].x;
                    all_path[i].y = all_path[i-1].y;
                }
                break;

            case 'L':
                cout<<"L";
                if(all_path[i-1].x - 1 >= -5){    
                    all_path[i].x = all_path[i-1].x - 1;
                    all_path[i].y = all_path[i-1].y;
                }
                else{
                    cout<<"Range over L"<<endl;
                    all_path[i].x = all_path[i-1].x;
                    all_path[i].y = all_path[i-1].y;
                }
                break;

            case 'R':
                cout<<"R";
                if(all_path[i-1].x + 1 <= 5){    
                    all_path[i].x = all_path[i-1].x + 1;
                    all_path[i].y = all_path[i-1].y;
                }
                else{
                    cout<<"Range over R"<<endl;
                    all_path[i].x = all_path[i-1].x;
                    all_path[i].y = all_path[i-1].y;
                }
                break;
        }
    }
    for(auto z : all_path){
        cout<<"{"<<z.x<<", "<<z.y<<"}"<<endl;
    }

    my_path[0] = {0,0};
    for(int j = 1; j <= dirs.size(); ++j){
        switch(dirs[j-1]){
            case 'U':
                if(my_path[j-1].y + 1 <= 5){
                    my_path[j].x = my_path[j-1].x;
                    my_path[j].y = my_path[j-1].y + 1;

                    for(int k = 1; k < j; ++k){
                        if(my_path[j-1].x == all_path[k-1].x && my_path[j-1].y == all_path[k-1].y && my_path[j].x == all_path[k].x && my_path[j].y == all_path[k].y){
                            cout<<"U DUP !!& J is : "<<j<<endl;
                            dup_len++;
                        }
                    }
                }
                break;

            case 'D':
                if(my_path[j-1].y - 1 >= -5){
                    my_path[j].x = my_path[j-1].x;
                    my_path[j].y = my_path[j-1].y - 1;

                    for(int k = 1; k < j; ++k){
                        if(my_path[j-1].x == all_path[k-1].x && my_path[j-1].y == all_path[k-1].y && my_path[j].x == all_path[k].x && my_path[j].y == all_path[k].y){
                            cout<<"D DUP !!& J is : "<<j<<endl;
                            dup_len++;
                        }
                    }
                }
                break;

            case 'L':
                if(my_path[j-1].x - 1 >= -5){
                    my_path[j].x = my_path[j-1].x - 1;
                    my_path[j].y = my_path[j-1].y;

                    for(int k = 1; k < j; ++k){
                        if(my_path[j-1].x == all_path[k-1].x && my_path[j-1].y == all_path[k-1].y && my_path[j].x == all_path[k].x && my_path[j].y == all_path[k].y){
                            cout<<"L DUP !!& J is : "<<j<<endl;
                            dup_len++;
                        }
                    }
                }
                break;

            case 'R':
                if(my_path[j-1].x + 1 <= 5){
                    my_path[j].x = my_path[j-1].x + 1;
                    my_path[j].y = my_path[j-1].y;

                    for(int k = 1; k < j; ++k){
                        if(my_path[j-1].x == all_path[k-1].x && my_path[j-1].y == all_path[k-1].y && my_path[j].x == all_path[k].x && my_path[j].y == all_path[k].y){
                            cout<<"R DUP !! & J is : "<<j<<endl;
                            dup_len++;
                        }
                    }
                }
                break;
        }
    }

    answer = path_len - dup_len;
    cout<<"PATH LEN : "<<path_len<<endl;
    cout<<"DUP_LEN : "<<dup_len<<endl;
    return answer;
}



int main(){
    string dirs1 = "ULURRDLLU";
    string dirs2 = "LULLLLLLU";

    cout<<solution(dirs2)<<endl;
    return 0;
}