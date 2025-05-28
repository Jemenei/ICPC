#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;



vector<int> dijkstra(int start, int n, const vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.emplace(0, start);



    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;

    vector<int> route(k);
    for (int i = 0; i < k; ++i) cin >> route[i];

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<tuple<int, int, int>> edges(m);

    set<pair<int, int>> path_edges;



    for (int i = 0; i + 1 < k; ++i) {
        int u = route[i], v = route[i + 1];
        if (u > v) swap(u, v);
        path_edges.emplace(u, v);
    }



    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
        edges[i] = {a, b, c};
    }



    auto dist1 = dijkstra(1, n, adj);
    auto distn = dijkstra(n, n, adj);
    int shortest = dist1[n];


    
    for (auto [u, v, w] : edges) {
        if (dist1[u] + w + distn[v] == shortest || dist1[v] + w + distn[u] == shortest) {
            int a = min(u, v), b = max(u, v);
            if (!path_edges.count({a, b})) {
                cout << "yes\n";
                return 0;
            }
        }
    }

    cout << "no\n";
    return 0;
}
