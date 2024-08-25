#include <iostream>
#include <vector>

using namespace std;

void DFS(int node, vector<vector<int>> &graph, vector<bool> &visited){
    visited[node] = true;
    cout<<node<<" ";

    for(int neighbor : graph[node]){
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

    vector<bool> visited(n, false);

    DFS(1, graph, visited);

    return 0;
}