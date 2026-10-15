#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    int totalCost = 0;

    while(pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();

        int cost = a + b;
        totalCost += cost;

        pq.push(cost);
    }

    cout << totalCost << endl;

    return 0;
}