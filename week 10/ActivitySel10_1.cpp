#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct acc{
    int start, end, index;
};

bool cmp(acc a, acc b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n), e(n);
    for(int i=0;i<n;i++) {
        cin >> s[i];
    }
    for(int i=0;i<n;i++) {
        cin >> e[i];
    }
    vector<acc> jobs;
    for(int i=0;i<n;i++) {
        jobs.push_back({s[i],e[i],i+1});
    }
    vector<int> sel;
    sort(jobs.begin(),jobs.end(),cmp);
    sel.push_back({jobs[0].index});
    int endt = jobs[0].end;
    for(int i=1;i<n;i++) {
        if(jobs[i].start>=endt) {
            sel.push_back({jobs[i].index});
            endt=jobs[i].end;
        }
    }
    cout << sel.size() << endl;
    for(int i=0;i<sel.size();i++) {
        cout << sel[i] << " ";
    }
}
