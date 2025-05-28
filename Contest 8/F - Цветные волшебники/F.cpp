#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int MAXN = 105;

vector<int> graph[MAXN];


vector<int> bfs(int start, int n) {
    vector<int> dist(n + 1, INF);
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : graph[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int f;
    cin >> f;


    vector<pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edges.emplace_back(u, v);
    }

    int k;
    cin >> k;

    vector<pair<int, int>> starts(k);
    for (int i = 0; i < k; ++i) {
        cin >> starts[i].first >> starts[i].second;
    }


    for (auto [yellowStart, blueStart] : starts) {

        auto dy = bfs(yellowStart, n);
        auto db = bfs(blueStart, n);
        auto df = bfs(f, n);

        int greenCount = 0;


        for (auto [u, v] : edges) {
            bool yellowUses = (dy[u] + 1 == dy[v]) || (dy[v] + 1 == dy[u]);
            bool blueUses = (db[u] + 1 == db[v]) || (db[v] + 1 == db[u]);

            if (yellowUses && blueUses) {
                greenCount++;
            }
        }

        cout << greenCount << '\n';
    }

    return 0;
}
