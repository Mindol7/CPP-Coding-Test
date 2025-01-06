#include <iostream>
#include <vector>

using namespace std;

/* DFS 재귀로 구하기
** STEP 1) 시작 노드를 호출한다.
** STEP 2) 시작 노드의 인접 노드를 호출한다 (반복문)
** STEP 3) 재귀적으로 호출한다.
** STEP 4) 
 */

void DFS(int n_, vector<vector<int>> &graph, vector<bool> &visited){
    visited[n_] = true; // 호출됨과 동시에 방문햇음
    cout<<n_<<" ";
    for(auto neighbor : graph[n_]){
        if(!visited[neighbor]){
            DFS(neighbor, graph, visited);
        }
    }
}


int main(){
    int n = 6;
    vector<vector<int>> graph(n);

    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 4};
    graph[3] = {1, 5};
    graph[4] = {1, 2, 5};
    graph[5] = {3, 4};

    vector<bool> visited(n, false); // 0 ~ 5 까지 노드임, 초기에는 false임
    DFS(0, graph, visited); // 0, 1, 3, 5, 4, 2
    return 0;
}