#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(vector<vector<int>> G, vector<int> &visited, stack<int> st, int s, int d) {
    st.push(s);
    visited[s]=1;
    while(!st.empty()) {
        int v = st.top();
        st.pop();
        for(int des : G[v]) {
            if(visited[des]==0)
                dfs(G,visited,st,des,d);
        }
        visited[v]=2;
    }
}

int main() {
    int v, e, s, d;
    cin >> v >> e;
    vector<vector<int>> G(v);
    for(int i=0;i<e;i++) {
        cin >> s >> d;
        G[s].push_back(d);
        G[d].push_back(s);
    }
    vector<int> visited(v,0);
    cin >> s;
    cin >> d;
    s--;
    d--;
    stack<int> st;
    dfs(G,visited,st,s,d);
    if(visited[d]==0) cout << "No Such Path Exists";
    else cout << "Yes Path Exists";
}
