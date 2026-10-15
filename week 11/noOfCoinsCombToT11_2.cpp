#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n,0);
    for(int i=0;i<n;i++) {
        cin >> coins[i];
    }
    int sum;
    cin >> sum;
    vector<int> dp(sum+1,0);
    dp[0]=1;
    for(int coin : coins) {
        for(int i=coin;i<=sum;i++) {
            dp[i]+=dp[i-coin];
        }
    }
    cout << dp[sum];
}