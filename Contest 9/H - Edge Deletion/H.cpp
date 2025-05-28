#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

struct Edge {
    int to, weight, index;
};



int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k; cin >> n >> m >> k;
    vector<vector<Edge>> adj(n + 1);
    vector<tuple<int, int, int>> all_edges(m + 1);


    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w, i});
        adj[v].push_back({u, w, i});
        all_edges[i] = {u, v, w};
    }



    vector<int> dist(n + 1, INF);
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w, idx] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }


    
    vector<vector<pair<int, int>>> tree(n + 1);
    for (int i = 1; i <= m; ++i) {
        auto [u, v, w] = all_edges[i];
        if (dist[u] + w == dist[v]) {
            tree[u].emplace_back(v, i);
        } else if (dist[v] + w == dist[u]) {
            tree[v].emplace_back(u, i);
        }
    }



    vector<bool> visited(n + 1, false);
    vector<int> result;
    queue<int> q;
    visited[1] = true;
    q.push(1);



    while (!q.empty() && result.size() < k) {
        int u = q.front(); q.pop();
        for (auto [v, id] : tree[u]) {
            if (!visited[v]) {
                visited[v] = true;
                result.push_back(id);
                q.push(v);
                if (result.size() == k) break;
            }
        }
    }



    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " \n"[i + 1 == result.size()];
    }

    return 0;
}
