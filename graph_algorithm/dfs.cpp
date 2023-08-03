#include <iostream>
#include <vector>
using namespace std;
vector<int> graph[100];
bool visited[100];


void dfs(int start) {
    if(visited[start])
        return;
    visited[start] = true;
    cout << start << " ";

   
    for (auto u: graph[start]) {
        dfs(u);
    }
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges: \n";
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    cout << "Depth-First Traversal: ";
    dfs(startNode);

    return 0;
}
