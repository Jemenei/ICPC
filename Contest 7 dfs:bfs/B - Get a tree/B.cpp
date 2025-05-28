#include <iostream>
#include <vector>
#include <utility>

using namespace std;



void dfs(int u, vector<bool>& visited, vector<vector<int> >& adj, vector<pair<int, int> >& treeEdges) {
    visited[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]) {
            treeEdges.push_back({u, v});
            dfs(v, visited, adj, treeEdges);
        }
    }
}



int main() {
    int n, m; cin >> n >> m;
    vector<vector<int> > adj(n + 1);

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<bool> visited(n + 1, false);
    vector<pair<int, int> > treeEdges;
    dfs(1, visited, adj, treeEdges);


    for(auto e : treeEdges) {
        cout << e.first << " " << e.second << endl;
    }

    return 0;
}