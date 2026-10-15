#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int can = arr[0], c=1;
    for(int i=1;i<n;i++) {
        if(can==arr[i]) {
            c++;
        }
        else {
            c--;
        }
        if(c==0) {
            can=arr[i];
            c=1;
        }
    }
    c=0;
    for(int i=0;i<n;i++) {
        if(can==arr[i]) c++;
    }
    if(c>n/2) cout << "yes" << endl;
    else cout << "no" << endl;
    sort(arr.begin(),arr.end());
    if(n%2==1) {
        cout << arr[n/2] << endl;
    }
    else {
        double m = (arr[n/2]+arr[n/2-1])/2.0;
        cout << m << endl;
    }
}