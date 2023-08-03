#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

// vector<Edge> E;
int dis[100];
int n;

void bellman_ford(int s, vector<Edge>& edges){
    for (int i = 0; i < n; i++){
        dis[i] = INT_MAX;
    }

    dis [s] = 0;

    for(int i = 0; i < n-1; i++){
        for(auto e: edges){
            tie(a, b, w) = e;
            // if (dis[e.u] + e.w < dis[e.v]){
            //     dis[e.v] = dis[e.u] + e.w;
            // }
            // same
            dis[e.v] = min(dis[e.v], dis[e.u] + e.w);
        }
    }


}

int main(){
    int V, E;
    cout << "Number of vertices and edges respectively: ";
    cin >> V >> E;
    vector<Edge> edges(E);
    
    cout << "Enter source, destination, and weight respectively: ";
    for (int i = 1; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int s;
    cin >> s >> n;
    bellman_ford(s, edges);
    
    cout << "Vertex \t distance from source\n";
    for(int i = 0; i < V; i++){
        cout << i << "\t" << dis[i] << "\n";
    }



}