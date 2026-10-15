#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main() {
    int v;
    cin >> v;
    vector<vector<pair<int,int>>> G(v);
    for(int i=0;i<v;i++) {
        for(int j=0;j<v;j++) {
            int wt;
            cin >> wt;
            if(wt!=0) {
                G[i].push_back({j,wt});
            }
        }
    }
    int src, des, k;
    cin >> src >> des >> k;
    src--;
    des--;
    vector<vector<int>> dp(k+1,vector<int> (v,INT_MAX));
    dp[0][src]=0;
    for(int i=1;i<=k;i++) {
        for(int j=0;j<v;j++) {
            if(dp[i-1][j]!=INT_MAX) {
                for(auto it : G[j]) {
                    int d = it.first;
                    int wt = it.second;
                    if(dp[i-1][j]+wt<dp[i][d]) {
                        dp[i][d] = dp[i-1][j] + wt;
                    }
                }
            }
        }
    }
    if(dp[k][des] == INT_MAX) {
        cout << "no path of length k is available";
    } else {
        cout << "Weight of shortest path from (" 
             << src+1 << "," << des+1 << ") with " 
             << k << " edges : " << dp[k][des];
    }
}