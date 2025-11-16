#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void topologicalSortUtil(int v, vector<vector<int> >& graph, vector<bool>& visited, stack<int>& Stack) {
    visited[v] = true;

    for (int i : graph[v]) {
        if (!visited[i])
            topologicalSortUtil(i, graph, visited, Stack);
    }

    Stack.push(v);
}

vector<int> topologicalSort(vector<vector<int> >& graph, int V) {
    vector<int> result;
    stack<int> Stack;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i])
            topologicalSortUtil(i, graph, visited, Stack);
    }

    while (!Stack.empty()) {
        result.push_back(Stack.top());
        Stack.pop();
    }

    return result;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int> > graph(V);

    cout << "Enter the edges (source destination):" << endl;
    for (int i = 0; i < E; ++i) {
        int source, destination;
        cin >> source >> destination;
        graph[source].push_back(destination);
    }

    cout << "Topological Order of vertices is: ";
    vector<int> sorted = topologicalSort(graph, V);
    for (int vertex : sorted)
        cout << vertex << " ";
    cout << endl;

    return 0;
}
