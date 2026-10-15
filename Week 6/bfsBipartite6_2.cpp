#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> G, vector<int> color, int v) {
    for(int i=0;i<v;i++) {
        if(color[i]==-1) {
            queue<int> q;
            q.push(i);
            color[i]=0;
            while(!q.empty()){
                int s = q.front();
                q.pop();
                for(int d:G[s]) {
                    if(color[d]==-1) {
                        q.push(d);
                        color[d]=1-color[s];
                    }
                    else if(color[d]==color[s]) {
                        cout << "Not Bipartite";
                        return;
                    }
                }
            }
        }
    }
    cout << "Bipartite";
}

int main() {
    int v, e, s, d;
    cin >> v >> e;
    vector<vector<int>> G(v);
    for(int i=0;i<e;i++) {
        cin >> s >> d;
        G[s].push_back(d);
        G[d].push_back(s);
    }
    vector<int> color(v,-1);
    bfs(G,color,v);
}