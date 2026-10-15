#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Task {
    int time, deadline, index;
};

bool cmp(Task a, Task b) {
    return a.deadline < b.deadline;
}

int main() {
    int n;
    cin >> n;

    vector<int> t(n), d(n);
    for(int i = 0; i < n; i++) cin >> t[i];
    for(int i = 0; i < n; i++) cin >> d[i];

    vector<Task> tasks;
    for(int i = 0; i < n; i++) {
        tasks.push_back({t[i], d[i], i+1});
    }

    // sort by deadline
    sort(tasks.begin(), tasks.end(), cmp);

    priority_queue<pair<int,int>> pq; // {time, index}
    int currentTime = 0;

    for(auto task : tasks) {
        currentTime += task.time;
        pq.push({task.time, task.index});

        // if exceeds deadline → remove largest task
        if(currentTime > task.deadline) {
            currentTime -= pq.top().first;
            pq.pop();
        }
    }

    // collect selected tasks
    vector<int> result;
    while(!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }

    sort(result.begin(), result.end());

    cout << "Max number of tasks = " << result.size() << endl;
    cout << "Selected task numbers : ";

    for(int i = 0; i < result.size(); i++) {
        cout << result[i];
        if(i != result.size()-1) cout << ", ";
    }

    return 0;
}