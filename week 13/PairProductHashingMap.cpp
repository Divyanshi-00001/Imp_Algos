#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    unordered_map<int, pair<int,int>> mp;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int prod = arr[i] * arr[j];

            if(mp.find(prod) != mp.end()) {
                auto p = mp[prod];
                cout << p.first << " " << p.second << endl;
                cout << arr[i] << " " << arr[j] << endl;
                return 0;
            } else {
                mp[prod] = {arr[i], arr[j]};
            }
        }
    }

    return 0;
}