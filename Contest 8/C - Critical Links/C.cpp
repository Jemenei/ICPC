#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10005];
vector<pair<int, int>> bridges;
int tin[10005], low[10005], timer;
bool visited[10005];

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                bridges.push_back({min(v, to), max(v, to)});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) adj[i].clear();

        for (int i = 0; i < n; i++) {
            int u, k;
            char ch;
            cin >> u >> ch >> k >> ch;
            for (int j = 0; j < k; j++) {
                int v;
                cin >> v;
                adj[u].push_back(v);
                if (find(adj[v].begin(), adj[v].end(), u) == adj[v].end())
                    adj[v].push_back(u);
            }
        }

        timer = 0;
        bridges.clear();
        fill(visited, visited + n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) dfs(i);
        }

        sort(bridges.begin(), bridges.end());

        cout << "Case " << c << ":\n";
        cout << bridges.size() << " critical links\n";
        for (auto b : bridges) {
            cout << b.first << " - " << b.second << "\n";
        }
        cout << "\n";
    }

    return 0;
}
