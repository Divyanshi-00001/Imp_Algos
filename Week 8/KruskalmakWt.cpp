#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge{
    int u, v, wt;
};

bool compare(edge a, edge b) {
    return a.wt>b.wt;
}
 
int findParent(int u, vector<int> &parent) {
    if(parent[u]==u) {
        return u;
    }
    return parent[u]=findParent(parent[u],parent);
}

void Union(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(u,parent);
    v = findParent(v,parent);
    if(rank[u]<rank[v]) {
        parent[u]=v;
    }
    else if(rank[u]>rank[v]) {
        parent[v]=u;
    }
    else {
        parent[v]=u;
        rank[u]++;
    }
}

void Kruskal(int v, vector<edge> &edges) {
    sort(edges.begin(),edges.end(),compare);
    vector<int> parent(v), rank(v,0);
    for(int i=0;i<v;i++) parent[i]=i;
    int tc=0;
    int c=0;
    for(auto it : edges) {
        if(findParent(it.u,parent)!=findParent(it.v,parent)) {
            tc+=it.wt;
            Union(it.u,it.v,parent,rank);
            c++;
            if(c==v-1) break;
        }
    }
    cout << tc;
}

int main() {
    int v;
    cin >> v;
    vector<edge> edges;
    for(int i=0;i<v;i++) {
        for(int j=0;j<v;j++) {
            int wt;
            cin>>wt;
            if(j > i && wt!=0) {
                edges.push_back({i,j,wt});
            }
        }
    }
    Kruskal(v,edges);
}