#include <iostream>
#include <vector>
#include <climits>

struct Edge {
    int source;
    int destination;
    int weight;
};

void BellmanFord(std::vector<Edge>& edges, int V, int source) {
    std::vector<int> distance(V, INT_MAX);
    distance[source] = 0;

    // Relax edges |V|-1 times
    for (int i = 0; i < V - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;

        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            std::cout << "Graph contains negative-weight cycle\n";
            return;
        }
    }

    // Print the shortest distances
    std::cout << "Vertex\tDistance from Source\n";
    for (int i = 1; i <= V; ++i) {
        std::cout << i << "\t" << distance[i] << "\n";
    }
}

int main() {
    int V, E; // Number of vertices and edges
    std::cout << "Enter the number of vertices: ";
    std::cin >> V;
    std::cout << "Enter the number of edges: ";
    std::cin >> E;

    std::vector<Edge> edges(E);

    std::cout << "Enter edge information in the following format:\n";
    std::cout << "Source Vertex Destination Vertex Weight\n";
    for (int i = 0; i < E; ++i) {
        std::cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    int source;
    std::cout << "Enter the source vertex: ";
    std::cin >> source;

    BellmanFord(edges, V, source);

    return 0;
}
