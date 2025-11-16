#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include<bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

int tspBranchAndBound(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> path(n);
    iota(path.begin(), path.end(), 0); // Initialize path with 0, 1, 2, ..., n-1

    int minCost = INF;

    do {
        int currentCost = 0;
        bool validPath = true;

        for (int i = 0; i < n - 1; ++i) {
            if (graph[path[i]][path[i + 1]] == INF) {
                validPath = false;
                break;
            }
            currentCost += graph[path[i]][path[i + 1]];
        }

        if (validPath && graph[path[n - 1]][path[0]] != INF) {
            currentCost += graph[path[n - 1]][path[0]];
            minCost = min(minCost, currentCost);
        }

    } while (next_permutation(path.begin() + 1, path.end()));

    return minCost;
}

int main() {
    vector<vector<int>> graph = {
        {INF, 10, 15, 20},
        {5,INF,9,10},
        {6,13,INF,12},
        {8,8,9,INF}
    };

    int minCost = tspBranchAndBound(graph);
    cout << "Minimum cost of TSP: " << minCost << endl;

    return 0;
}
