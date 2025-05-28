#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> d, up;
vector<bool> visited;
int timer = 0;
vector<bool> is_articulation;

void dfs(int v, int p = -1) {
    visited[v] = true;
    d[v] = up[v] = ++timer;
    int children = 0;
    for (int u : adj[v]) {
        if (u == p) continue;
        if (visited[u]) {
            up[v] = min(up[v], d[u]);
        } else {
            dfs(u, v);
            up[v] = min(up[v], up[u]);
            if (up[u] >= d[v] && p != -1) {
                is_articulation[v] = true;
            }
            ++children;
        }
    }
    if (p == -1 && children > 1) {
        is_articulation[v] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int n, m;
        cin >> n >> m;
        
        adj.assign(n + 1, vector<int>());
        d.assign(n + 1, 0);
        up.assign(n + 1, 0);
        visited.assign(n + 1, false);
        is_articulation.assign(n + 1, false);
        timer = 0;
        
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        for (int v = 1; v <= n; ++v) {
            if (!visited[v]) {
                dfs(v);
            }
        }
        
        int result = count(is_articulation.begin(), is_articulation.end(), true);
        cout << "Case " << tc << ": " << result << "\n";
    }
    
    return 0;
}