#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int start, vector<vector<int>> &graph, vector<bool> &visited){
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";

        for(int neighbor : graph[node]){
            if(!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main(){
    int n = 6;
    vector<vector<int>> graph(n);

    graph[0] = {1,2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 4};
    graph[3] = {1, 5};
    graph[4] = {1, 2, 5};
    graph[5] = {3, 4};

    vector<bool> visited(n, false);

    BFS(0, graph, visited);

    return 0;
}