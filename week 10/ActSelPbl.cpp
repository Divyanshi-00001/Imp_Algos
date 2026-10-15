#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start, end, index;
};

bool cmp(Activity a, Activity b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;

    vector<int> start(n), end(n);
    for(int i = 0; i < n; i++) cin >> start[i];
    for(int i = 0; i < n; i++) cin >> end[i];

    vector<Activity> activities;
    for(int i = 0; i < n; i++) {
        activities.push_back({start[i], end[i], i + 1}); // store 1-based index
    }

    // Sort by finishing time
    sort(activities.begin(), activities.end(), cmp);

    vector<int> selected;

    // Select first activity
    selected.push_back(activities[0].index);
    int lastEnd = activities[0].end;

    // Select remaining
    for(int i = 1; i < n; i++) {
        if(activities[i].start >= lastEnd) {
            selected.push_back(activities[i].index);
            lastEnd = activities[i].end;
        }
    }

    // Output
    cout << "No. of non-conflicting activities: " << selected.size() << endl;
    cout << "List of selected activities: ";

    for(int i = 0; i < selected.size(); i++) {
        cout << selected[i];
        if(i != selected.size() - 1) cout << ", ";
    }

    return 0;
}