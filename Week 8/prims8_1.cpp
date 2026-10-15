#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void prims(int v, vector<vector<pair<int,int>>> &G) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<bool> visited(v,false);
    int tc=0;
    pq.push({0,0});
    while(!pq.empty()) {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(visited[node]==true) continue;
        visited[node]=true;
        tc+=wt;
        for(auto it : G[node]) {
            int wt1 = it.first;
            int next = it.second;
            if(!visited[next]) {
                pq.push({wt1,next});
            }
        }
    }
    cout << tc;
}

int main() {
    int v, e, s, d, w;
    cin >> v >> e;
    vector<vector<pair<int,int>>> G(v);
    for(int i=0;i<e;i++) {
        cin >> s >> d >> w;
        G[s].push_back({w,d});
        G[d].push_back({w,s});
    }
    prims(v,G);
}