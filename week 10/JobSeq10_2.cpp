#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct task{
    int t, d, i;
};

bool cmp(task a, task b) {
    return a.d < b.d;
}

int main() {
    int n;
    cin >> n;
    vector<int> t(n), d(n);
    for(int i=0;i<n;i++) {
        cin >> t[i];
    }
    for(int i=0;i<n;i++) {
        cin >> d[i];
    }
    vector<task> tasks;
    for(int i=0;i<n;i++) {
        tasks.push_back({t[i],d[i],i+1});
    }
    priority_queue<pair<int,int>> pq;
    sort(tasks.begin(),tasks.end(),cmp);
    int ct=0;
    for(task t : tasks) {
        ct+=t.t;
        pq.push({t.t,t.i});
        if(ct>t.d) {
            int mt=pq.top().first;
            pq.pop();
            ct-=mt;
        }
    }
    vector<int> result;
    while(!pq.empty()) {
        result.push_back({pq.top().second});
        pq.pop();
    }
    sort(result.begin(),result.end());
    cout<<result.size() << endl;
    for(int v : result) {
        cout << v << " ";
    }
}