#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

vector<int> g[MAXN];
vector<int> reverse_g[MAXN];
int out_deg[MAXN];
double prob[MAXN];
bool reachable[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;
    --r;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        reverse_g[v].push_back(u);
        ++out_deg[u];
    }

    queue<int> q;
    reachable[r] = true;
    q.push(r);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (!reachable[v]) {
                reachable[v] = true;
                q.push(v);
            }
        }
    }

    vector<int> topo;
    vector<int> in_deg(n);
    for (int u = 0; u < n; ++u)
        for (int v : g[u])
            ++in_deg[v];

    q.push(r);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int v : g[u])
            if (--in_deg[v] == 0)
                q.push(v);
    }

    prob[r] = 1.0;
    for (int u : topo)
        for (int v : g[u])
            prob[v] += prob[u] / g[u].size();

    double best = 0.0;
    vector<int> result;
    for (int i = 0; i < n; ++i) {
        if (reachable[i] && g[i].empty()) {
            if (abs(prob[i] - best) <= 1e-9)
                result.push_back(i + 1);
            else if (prob[i] > best) {
                best = prob[i];
                result = {i + 1};
            }
        }
    }

    for (int x : result)
        cout << x << " ";
    cout << "\n";
    return 0;
}
