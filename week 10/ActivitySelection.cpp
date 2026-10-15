#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.second<b.second;
}

int bs(vector<pair<int,int>> &ac, vector<int> &dp, int i) {
    for(int j=i-1;j>=0;j--) {
        if(ac[j].second<=ac[i].first) {
            return dp[j+1];
        }
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    for(int i=0;i<n;i++) {
        cin >> v1[i];
    }
    for(int i=0;i<n;i++) {
        cin >> v2[i];
    }
    vector<pair<int,int>> ac;
    for(int i=0;i<n;i++) {
        ac.push_back({v1[i],v2[i]});
    }
    sort(ac.begin(),ac.end(),cmp);
    vector<int> dp(n+1,0);
    dp[0]=0;
    for(int i=1;i<=n;i++) {
        dp[i] = max(dp[i-1],bs(ac,dp,i-1)+1);
    }
    cout << dp[n];
}