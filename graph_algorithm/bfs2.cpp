#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100];
bool visited[100];
queue<int> q;

void bfs(int start) {
    visited[start] = true;
    graph[start] = {0};
    q.push(start);

    while (!q.empty()) {
        int s = q.front();
        q.pop();
        cout << s << " ";  

        
        for (auto u : graph[s]) {
            if (visited[u]) continue;
            
            visited[u] = true;
            q.push(u);          
        }
    }
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> graph(numNodes);

    cout << "Enter the edges (node1 node2):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    cout << "BFS traversal starting from node " << startNode << ": ";
    bfs(startNode);

    return 0;
}
