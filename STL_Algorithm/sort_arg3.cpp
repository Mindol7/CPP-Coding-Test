#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point{
    int x, y;

    Point(int x, int y) : x(x), y(y){};
};

/* 사용자 정의 비교 함수 */
bool compare(const Point &a, const Point &b){
    if(a.x == b.x){ // 서로 x좌표가 같으면 y좌표 작은 순서대로 정렬
        return a.y < b.y; // 앞에 놈이 크면 false를 return하니까 순서가 바뀜, 즉, y좌표가 작은 놈을 앞에 오게하는거임
    }

    return a.x < b.x; // 서로 x좌표가 다르면 x좌표 작은 순서대로 정렬, 앞에 놈이 크면 false를 return하니까 순서가 바뀜, 즉, x좌표가 작은 놈을 앞에 오게 하는거임
}

int main(){
    vector<Point> points = {{3,4}, {1,2}, {3,1}, {2,5}};

    sort(points.begin(), points.end(), compare);

    for(const auto &p : points){
        cout<<"("<<p.x<<", "<<p.y<<") ";
    }
    cout<<endl;

    return 0;
}