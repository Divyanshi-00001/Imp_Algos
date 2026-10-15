#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // -------- Majority Element (Boyer-Moore) --------
    int candidate = arr[0], count = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == candidate)
            count++;
        else
            count--;

        if (count == 0) {
            candidate = arr[i];
            count = 1;
        }
    }

    // Verify candidate
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate)
            count++;
    }

    if (count > n / 2)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    // -------- Median --------
    sort(arr.begin(), arr.end());

    if (n % 2 == 1) {
        cout << arr[n / 2] << endl;
    } else {
        double median = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
        cout << median << endl;
    }

    return 0;
}