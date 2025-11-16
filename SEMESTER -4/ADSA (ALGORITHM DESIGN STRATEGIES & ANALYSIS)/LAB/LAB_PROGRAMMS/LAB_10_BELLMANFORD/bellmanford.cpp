#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Structure to represent an edge
struct Edge {
    int source, destination, weight;
};

// Function to perform Bellman-Ford algorithm
void bellmanFord(vector<Edge>& edges, int numVertices, int source) {
    vector<int> distance(numVertices,9999); // Initialize distances to infinity
    distance[source] = 0; // Distance from source to itself is 0

    // Relax edges repeatedly
    for (int i = 0; i < numVertices - 1; i++) {
        for (const auto& edge : edges) {
            if (distance[edge.source] != 9999 && 
                distance[edge.source] + edge.weight < distance[edge.destination]) {
                distance[edge.destination] = distance[edge.source] + edge.weight;
            }
        }
    }

    // Check for negative weight cycles
    for (const auto& edge : edges) {
        if (distance[edge.source] != 9999 && 
            distance[edge.source] + edge.weight < distance[edge.destination]) {
            cout << "Graph contains a negative weight cycle" << endl;
            return;
        }
    }

    // Print the shortest distances from the source
    cout << "Shortest distances from source vertex " << source << ":" << endl;
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertex " << i << ": " << distance[i] << endl;
    }
}

int main() {
    // Example graph represented as a list of edges
    vector<Edge> edges = {
        {0, 1, 6}, {0, 2, 7}, {1, 2, 8}, {1, 3, 5}, {1,4,-4}, {2,3,-3},{2,4,9},{3,1,-2},{4,0,2},{4,3,7}
    };

    int numVertices = 5; // Number of vertices in the graph
    int sourceVertex = 0; // Source vertex for Bellman-Ford algorithm

    bellmanFord(edges, numVertices, sourceVertex);

    return 0;
}


