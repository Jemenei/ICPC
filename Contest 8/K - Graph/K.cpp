#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<vector<int>> graph;
vector<int> in_deg;
unordered_set<long long> existing_edges;

long long encode(int u, int v) {
    return 1LL * u * 100000 + v; 
}

void topological_sort(const vector<vector<int>>& g, vector<int>& in, vector<int>& res) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; ++i)
        if (in[i] == 0)
            pq.push(i);

    res.clear();
    while (!pq.empty()) {
        int u = pq.top(); pq.pop();
        res.push_back(u);
        for (int v : g[u]) {
            if (--in[v] == 0)
                pq.push(v);
        }
    }
}

bool creates_cycle(int u, int v, const vector<vector<int>>& g) {
    queue<int> q;
    vector<bool> visited(n + 1, false);
    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == u) return true;
        for (int next : g[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    graph.resize(n + 1);
    in_deg.assign(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        in_deg[v]++;
        existing_edges.insert(encode(u, v));
    }

    vector<int> topo, in_copy = in_deg;
    topological_sort(graph, in_copy, topo);

    vector<pair<int, int>> added_edges;
    for (int i = 0; i < n && (int)added_edges.size() < k; ++i) {
        for (int j = i + 1; j < n && (int)added_edges.size() < k; ++j) {
            int u = topo[i], v = topo[j];
            if (existing_edges.count(encode(u, v))) continue;
            if (!creates_cycle(u, v, graph)) {
                graph[u].push_back(v);
                in_deg[v]++;
                existing_edges.insert(encode(u, v));
                added_edges.emplace_back(u, v);
            }
        }
    }

    in_copy = in_deg;
    topological_sort(graph, in_copy, topo);

    for (int x : topo) cout << x << " ";
    cout << "\n";

    cout << added_edges.size() << "\n";
    for (auto& p : added_edges)
        cout << p.first << " " << p.second << "\n";

    return 0;
}
