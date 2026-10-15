#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
void prims(int v, vector<vector<pair<int,int>>> &G) {
    priority_queue<pair<int,int>> pq;
    vector<bool> visited(v,false);
    int tc = 0;
    pq.push({0,0});
    while(!pq.empty()) {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(visited[node]) continue;
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
    cout << "Maximum Spanning Weight: " << tc << endl;
} 

int main() {
    int v;
    cin >> v;
    vector<vector<pair<int,int>>> G(v); 
    for(int i=0;i<v;i++) {
        for(int j=0; j<v;j++) {
            int wt;
            cin >> wt;
            if(wt!=0) {
                G[i].push_back({wt,j});
            }
        }
    }
    prims(v,G);
}