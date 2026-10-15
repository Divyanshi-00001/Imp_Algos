#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void prims(int V, vector<vector<pii>> &adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> visited(V, false);

    pq.push({0, 0}); // {weight, node}
    int totalCost = 0;

    while (!pq.empty()) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;
        totalCost += weight;

        for (auto &neighbor : adj[u]) {
            int v = neighbor.first;
            int wt = neighbor.second;

            if (!visited[v]) {
                pq.push({wt, v});
            }
        }
    }

    cout << "Total cost of MST: " << totalCost;
}