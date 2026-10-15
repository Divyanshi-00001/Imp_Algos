#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int node, vector<int> &parent) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node], parent);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

int kruskal(int V, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(V), rank(V, 0);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int totalCost = 0;

    for (auto &edge : edges) {
        if (findParent(edge.u, parent) != findParent(edge.v, parent)) {
            totalCost += edge.weight;
            unionSet(edge.u, edge.v, parent, rank);
        }
    }

    return totalCost;
}

int main() {
    int V = 7;

    vector<Edge> edges = {
        {0,2,7}, {0,3,5},
        {1,2,8}, {1,3,5},
        {2,3,9}, {2,4,7},
        {3,4,15}, {3,5,6},
        {4,5,8}, {4,6,9},
        {5,6,11}
    };

    cout << "Minimum Spanning Weight: " << kruskal(V, edges);

    return 0;
}