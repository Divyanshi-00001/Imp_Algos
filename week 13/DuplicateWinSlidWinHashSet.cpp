#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];

        int k;
        cin >> k;

        unordered_set<int> s;
        bool found = false;

        for(int i = 0; i < n; i++) {
            if(s.find(arr[i]) != s.end()) {
                found = true;
                break;
            }

            s.insert(arr[i]);

            if(s.size() > k) {
                s.erase(arr[i - k]);
            }
        }

        if(found)
            cout << "Duplicate present in window " << k << "." << endl;
        else
            cout << "Duplicate not present in window " << k << "." << endl;
    }

    return 0;
}