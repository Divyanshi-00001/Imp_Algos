#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for(int i=0;i<n;i++) {
        cin >> coins[i];
    }
    int t;
    cin >> t;
    vector<int> dp(t+1,0);
    dp[0]=1;
    for(int coin : coins) {
        for(int j=coin;j<=t;j++){
            dp[j]+=dp[j-coin];
        }
    }
    cout << dp[t];
}
