#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Edge {
    int src, dest, weight;
};

struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);

        if (rank[u] > rank[v]) {
            parent[v] = u;
        } else {
            parent[u] = v;
            if (rank[u] == rank[v]) {
                rank[v]++;
            }
        }
    }
};

bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

pair<vector<Edge>, int> kruskalMST(vector<Edge>& edges, int V) {
    // Sort edges based on weight
    sort(edges.begin(), edges.end(), compareEdges);

    vector<Edge> MST; // Stores the MST
    int minCost = 0;

    // Create a disjoint set for each vertex
    DisjointSet ds(V);

    for (const Edge &edge : edges) {
        int u = edge.src;
        int v = edge.dest;
        int weight = edge.weight;

        // If including this edge doesn't form a cycle
        if (ds.find(u) != ds.find(v)) {
            MST.push_back({u, v, weight});
            minCost += weight;
            ds.merge(u, v);
        }
    }

    return {MST, minCost};
}

int main() {
    int V, E; // Number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    // Input edges
    cout << "Enter edges in the format 'src dest weight':" << endl;
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    auto result = kruskalMST(edges, V);
    vector<Edge> MST = result.first;
    int minCost = result.second;
    cout << "Edges of Minimum Spanning Tree:" << endl;
    for (const Edge& edge : MST) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }
    cout << "Total Minimum Cost: " << minCost << endl;

    return 0;
}

	

