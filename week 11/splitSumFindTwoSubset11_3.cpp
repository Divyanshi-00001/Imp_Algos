#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i=0;i<n;i++) {
        cin >> vec[i];
    }
    int sum=0;
    for(int i=0;i<n;i++) {
        sum+=vec[i];
    }
    if(sum%2==1) {
        cout << "no" << endl;
        return 0;
    }
    sum/=2;
    vector<bool> dp(sum+1,false);
    dp[0]=true;
    for(int i=0;i<n;i++) {
        for(int j=sum;j>=vec[i];j--) {
            dp[j]=dp[j]||dp[j-vec[i]];
        }
    }
    if(dp[sum]) cout<<"yes";
    else cout<<"no";
}