#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void Rparent(int i, vector<int> &parent) {
    if(i==-1) return;
    cout << i+1 << " ";
    Rparent(parent[i],parent);
}

void print(int v, vector<int> &dest, vector<int> &parent) {
    for(int i=0;i<v;i++) {
        Rparent(i,parent);
        cout << ": " << dest[i] << endl;
    }
}

void Dijikstra(int v, vector<vector<pair<int,int>>> &G, int d) {
    vector<int> dest(v,INT_MAX), parent(v,-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dest[d]=0;
    pq.push({dest[d],d});
    while(!pq.empty()) {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(wt > dest[node]) continue; 
        for(auto des : G[node]) {
            int weight = des.first;
            int next = des.second;
            if(wt+weight<dest[next]) {
                dest[next] = wt+weight;
                parent[next] = node;
                pq.push({dest[next],next});
            }
        }
    }
    print(v,dest,parent);
}

void normalize(int v, vector<vector<int>> &G, int d) {
    vector<vector<pair<int,int>>> G1(v);
    for(int i=0;i<v;i++) {
        for(int j=0;j<v;j++) {
            if(G[i][j]!=0) {
                G1[j].push_back({G[i][j],i});
                //G1[i].push_back({G[i][j],j});
            }
        }
    }
    Dijikstra(v,G1,d);
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
    normalize(v,G,d);
}