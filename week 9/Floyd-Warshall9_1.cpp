#include <iostream>
#include <vector>
using namespace std;

#define INF 99999

void floydWarshall(int V, vector<vector<int>>& graph) {
    vector<vector<int>> dist = graph;

    // Floyd Warshall Algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print result
    cout << "Shortest distances between all pairs:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V, e, s, d, w;
    cin >> V >> e;

    // Initialize graph with INF and 0 on diagonal
    vector<vector<int>> graph(V, vector<int>(V, INF));
    for (int i = 0; i < V; i++) graph[i][i] = 0;

    // Read edges
    for (int i = 0; i < e; i++) {
        cin >> s >> d >> w;
        graph[s][d] = w;
    }

    floydWarshall(V, graph);
    return 0;
}
