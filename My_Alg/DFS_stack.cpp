#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/* DFS 작동 원리 
** STEP 1) 시작 노드를 push한다.
** STEP 2) pop하여 방문 여부 확인하고, 방문했으면 아무 것도 하지말고, 방문 안했으면 방문 처리하고 인접 노드 push 한다.
*/

void DFS(int n_, vector<vector<int>> &graph, vector<bool> &visited){
    stack<int> stack;
    int start_node = 0;
    stack.push(start_node);

    while(true){
        if(stack.empty()){ // stack이 비어있으면 모두 방문한 것임
            return;
        }
        
        int node = stack.top();
        stack.pop();
        if(visited[node] == false){
            cout << node << endl;
            visited[node] = true;
            for(int i = graph[node].size() - 1; i >= 0; i--) stack.push(graph[node][i]);
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
    DFS(n, graph, visited); // 0, 1, 3, 5, 4, 2

    return 0;
}