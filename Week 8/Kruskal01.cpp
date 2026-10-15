#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    int u, v, wt;
};

bool compare(edge a, edge b){
    return a.wt<b.wt;
}

int findParent(int u, vector<int> &parent) {
    if(parent[u]==u) {
        return u;
    }
    return parent[u] = findParent(parent[u],parent);
}

void setUnion(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(u,parent);
    v = findParent(v,parent);

    if(rank[u]<rank[v]) {
        parent[u]=v;
    }
    else if(rank[u]>rank[v]) {
        parent[v]=u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int Kruskal(vector<edge> &edges, int v) {
    sort(edges.begin(),edges.end(),compare);
    vector<int> parent(v), rank(v,0);
    for(int i=0;i<v;i++) parent[i]=i;
    int totalCost=0;
    for(edge &e : edges) {
        if(findParent(e.u,parent)!=findParent(e.v,parent)){
            totalCost+=e.wt;
            setUnion(e.u,e.v,parent,rank);
        }
    }
    return totalCost;
}

int main() {
    int n, e, u, v, wt;
    cin >> n >> e;
    vector<edge> edges;
    for(int i=0;i<e;i++) {
        cin >> u >> v >> wt;
        edges.push_back({u,v,wt});
    }
    int ans = Kruskal(edges,n);
    cout << ans;
}