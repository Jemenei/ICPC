#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 10005;
vector<int> adj[MAX];
bool visited[MAX];
int tin[MAX], low[MAX], timer;
vector<pair<int, int>> bridges;

void dfs(int v, int p) {
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

int comp[MAX], comp_id;
void paint(int v, int c) {
    comp[v] = c;
    visited[v] = true;
    for (int to : adj[v]) {
        if (visited[to]) continue;
        if (find(bridges.begin(), bridges.end(), make_pair(min(v, to), max(v, to))) != bridges.end()) continue;
        paint(to, c);
    }
}

int deg[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            adj[i].clear();
            deg[i] = 0;
        }
        bridges.clear();

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        memset(visited, 0, sizeof(visited));
        timer = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) dfs(i, -1);
        }

        memset(visited, 0, sizeof(visited));
        comp_id = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) paint(i, comp_id++);
        }

        for (auto e : bridges) {
            int a = comp[e.first];
            int b = comp[e.second];
            deg[a]++;
            deg[b]++;
        }

        int leaves = 0;
        for (int i = 0; i < comp_id; i++) {
            if (deg[i] == 1) leaves++;
        }

        cout << "Case " << t << ": " << (leaves + 1) / 2 << "\n";
    }

    return 0;
}
