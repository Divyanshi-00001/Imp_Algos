#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool dfs(vector<vector<int>> &G, vector<int> &visited, int v) {
    stack<int> st;
    st.push(v);
    visited[v]=1;
    while(!st.empty()) {
        int s = st.top();
        st.pop();
        for(int d : G[s]) {
            if(visited[d]==0)
                return dfs(G,visited,d);
            else return false;
        }
    }
    return true;
}

int main() {
    int v, e, s, d;
    cin >> v >> e;
    vector<vector<int>> G(v);
    for(int i=0;i<e;i++) {
        cin >> s >> d;
        G[s].push_back(d);
    }
    vector<int> visited(v,0);
    if(dfs(G,visited,0)) cout << "No Cycle Exists";
    else cout << "Yes Cycle Exists";
}