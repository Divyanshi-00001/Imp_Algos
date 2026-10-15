#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct edge {
    int u, v, wt;
};

void Rprint(int i, vector<int> &parent) {
    if(i==-1) return;
    cout << i+1 << " ";
    Rprint(parent[i],parent);
}

int main() {
    int v, d;
    cin >> v;
    vector<vector<int>> G(v,vector<int> (v,0));
    for(int i=0;i<v;i++) {
        for(int j=0;j<v;j++) {
            cin >> G[i][j];
        }
    }
    cin >> d;
    d--;
    vector<edge> edges;
    for(int i=0;i<v;i++) {
        for(int j=0;j<v;j++) {
            if(G[i][j]!=0) {
                edges.push_back({i,j,G[i][j]});
            }
        }
    }
    vector<int> dist(v,INT_MAX);
    vector<int> parent(v,-1);
    parent[d]=-1;
    dist[d]=0;
    for(int i=0;i<v-1;i++) {
        for(auto e:edges) {
            if(dist[e.u]!=INT_MAX && dist[e.u]+e.wt<dist[e.v]) {
                dist[e.v]=dist[e.u]+e.wt;
                parent[e.v]=e.u;
            }
        }
    }
    for(auto e: edges) {
        if(dist[e.u] != INT_MAX && dist[e.u] + e.wt < dist[e.v]) {
            cout << "Negative cycle detected";
            return 0;
        }
    }
    for(int i=0;i<v;i++) {
        Rprint(i,parent);
        cout << ": " << dist[i] << endl;
    }
}