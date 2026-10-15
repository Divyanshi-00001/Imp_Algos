#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> wt(n), val(n);
    for(int i = 0; i < n; i++) cin >> wt[i];
    for(int i = 0; i < n; i++) cin >> val[i];

    int W;
    cin >> W;

    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    // Build DP table
    for(int i = 1; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(wt[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], 
                               val[i-1] + dp[i-1][w - wt[i-1]]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    // Maximum value
    cout << "Value = " << dp[n][W] << endl;

    // Backtracking to find selected items
    int w = W;
    vector<int> selected_wt, selected_val;

    for(int i = n; i > 0; i--) {
        if(dp[i][w] != dp[i-1][w]) {
            selected_wt.push_back(wt[i-1]);
            selected_val.push_back(val[i-1]);
            w -= wt[i-1];
        }
    }

    cout << "Weights selected : ";
    for(int x : selected_wt) cout << x << " ";
    cout << endl;

    cout << "Values of selected weights : ";
    for(int x : selected_val) cout << x << " ";
    cout << endl;

    return 0;
}