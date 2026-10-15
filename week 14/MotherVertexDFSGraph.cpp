#include <iostream>
#include <vector>
using namespace std;

void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    for(int u : adj[v]) {
        if(!visited[u]) dfs(u, adj, visited);
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<bool> visited(V, false);
    int lastV = 0;

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            dfs(i, adj, visited);
            lastV = i;
        }
    }

    // Verify
    fill(visited.begin(), visited.end(), false);
    dfs(lastV, adj, visited);

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            cout << "No mother vertex";
            return 0;
        }
    }

    cout << "Mother Vertex: " << lastV;

    return 0;
}