#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    int sum = 0;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    // If sum is odd → not possible
    if(sum % 2 != 0) {
        cout << "no";
        return 0;
    }

    int target = sum / 2;

    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for(int i = 0; i < n; i++) {
        //for(int j = target; j >= arr[i]; j--) {
        for(int j = arr[i]; j <= target; j++) {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }

    if(dp[target]) cout << "yes";
    else cout << "no";

    return 0;
}