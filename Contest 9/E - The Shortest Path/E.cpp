#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;



int main() {
    int n, m; cin >> n >> m;
    int s, f; cin >> s >> f;



    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }



    vector<long long> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    dist[s] = 0;



    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, s});



    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }


    
    if (dist[f] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[f] << endl;
        vector<int> path;
        for (int v = f; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        for (int v : path) cout << v << " ";
        cout << endl;
    }

    return 0;
}
