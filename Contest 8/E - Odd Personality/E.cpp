#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 10005;
vector<int> g[MAX];
bool visited[MAX];
int color[MAX];

bool isBipartite(int start, int &cnt) {
    queue<int> q;
    q.push(start);
    color[start] = 0;
    visited[start] = true;
    cnt = 1;
    bool is_bipartite = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (!visited[v]) {
                visited[v] = true;
                color[v] = 1 - color[u];
                q.push(v);
                cnt++;
            } else if (color[v] == color[u]) {
                is_bipartite = false;
            }
        }
    }
    return is_bipartite;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m;
        cin >> n >> m;

        // Очистка графа
        for (int i = 0; i < n; i++) {
            g[i].clear();
            visited[i] = false;
        }

        // Чтение рёбер
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int cnt = 0;
                if (!isBipartite(i, cnt)) {
                    result += cnt;
                }
            }
        }

        cout << "Case " << t << ": " << result << "\n";
    }

    return 0;
}
