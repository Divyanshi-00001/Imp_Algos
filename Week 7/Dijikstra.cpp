#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

void Rprint(int i, vector<int> &parent) {
    if(i==-1) return;
    //cout << i+1 << " ";
    Rprint(parent[i],parent);
    cout << i << " ";
}

void print(int v, vector<int> &dist, vector<int> &parent) {
    for(int i=0;i<v;i++) {
        Rprint(i,parent);
        cout << ": " << dist[i] << endl;
    }
}

void Dijikstra(int v, vector<vector<pair<int,int>>> &G, int s) {
    vector<int> dist(v,INT_MAX), parent(v,-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[s]=0;
    pq.push({dist[s],s});
    while(!pq.empty()) {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(wt>dist[node]) continue;
        for(auto d : G[node]) {
            int weight = d.first;
            int next = d.second;
            if(wt+weight<dist[next]) {
                dist[next] = wt+weight;
                parent[next]=node;
                pq.push({dist[next],next});
            }
        }
    }
    print(v,dist,parent);
}

int main() {
    int v, e, s, d, w;
    cin >> v >> e;
    vector<vector<pair<int,int>>> G(v);
    for(int i=0;i<e;i++) {
        cin >> s >> d >> w;
        G[s].push_back({w,d});
    }
    cin >> s;
    //s--;
    Dijikstra(v,G,s);
}


