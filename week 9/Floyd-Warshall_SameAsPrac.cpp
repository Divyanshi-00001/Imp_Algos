#include <iostream>
#include <vector>

using namespace std;

#define INF 99999

void floyd(int v, vector<vector<int>> G) {
    vector<vector<int>> dis = G;
    for(int k=0;k<v;k++) {
        for(int i=0;i<v;i++) {
            for(int j=0;j<v;j++) {
                if(dis[i][k]+dis[k][j]<dis[i][j]) {
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    cout << "Shortest Distance Matrix: " << endl;
    for(int i=0;i<v;i++) {
        for(int j=0;j<v;j++) {
            if(dis[i][j]==INF) {
                cout << "INF";
            }
            else {
                cout << dis[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    int s, d, w;
    vector<vector<int>> G(v,vector<int> (v,INF));
    for(int i=0;i<v;i++) G[i][i]=0;

    for(int i=0;i<e;i++) {
        cin >> s >> d >> w;
        G[s][d] = w;
    }

    floyd(v,G);
}