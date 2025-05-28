#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int INF = 1e9;

struct State {
    int node, idx, cost;
    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int N, M, X; cin >> N >> M >> X;
        string S; cin >> S;

        string labels = "";
        for (int i = 0; i < N; ++i) {
            char ch;
            cin >> ch;
            labels += ch;
        }



        vector<vector<pii>> adj(N);
        for (int i = 0; i < M; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            --u; --v;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }



        vector<vector<int>> dist(N, vector<int>(X + 1, INF));
        priority_queue<State, vector<State>, greater<State>> pq;



        for (int i = 0; i < N; ++i) {
            if (labels[i] == S[0]) {
                dist[i][1] = 0;
                pq.push({i, 1, 0});
            }
            dist[i][0] = 0;
            pq.push({i, 0, 0});
        }



        while (!pq.empty()) {
            State cur = pq.top(); pq.pop();
            int u = cur.node, idx = cur.idx, cost = cur.cost;
            if (dist[u][idx] < cost) continue;

            for (auto [v, w] : adj[u]) {
                if (cost + w < dist[v][idx]) {
                    dist[v][idx] = cost + w;
                    pq.push({v, idx, dist[v][idx]});
                }
                if (idx < X && labels[v] == S[idx]) {
                    if (cost + w < dist[v][idx + 1]) {
                        dist[v][idx + 1] = cost + w;
                        pq.push({v, idx + 1, dist[v][idx + 1]});
                    }
                }
            }
        }



        int res = INF;
        for (int i = 0; i < N; ++i)
            res = min(res, dist[i][X]);

        cout << (res == INF ? -1 : res) << '\n';
    }

    return 0;
}
