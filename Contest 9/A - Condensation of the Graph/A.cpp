#include <bits/stdc++.h>
using namespace std;

const int MAX = 10005;

vector<vector<int>> g, gr;
vector<bool> used;
vector<int> order, component;
int n, m;



void dfs1(int v) {
    used[v] = true;
    for (int u : g[v])
        if (!used[u])
            dfs1(u);
    order.push_back(v);
}



void dfs2(int v, int label) {
    component[v] = label;
    for (int u : gr[v])
        if (component[u] == -1)
            dfs2(u, label);
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    cin >> n >> m;
    g.assign(n, {});
    gr.assign(n, {});



    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }



    used.assign(n, false);
    for (int i = 0; i < n; ++i)
        if (!used[i])
            dfs1(i);



    component.assign(n, -1);
    int label = 0;
    reverse(order.begin(), order.end());
    for (int v : order)
        if (component[v] == -1)
            dfs2(v, label++);



    set<pair<int, int>> condensed_edges;
    for (int u = 0; u < n; ++u) {
        for (int v : g[u]) {
            int cu = component[u];
            int cv = component[v];
            if (cu != cv) {
                condensed_edges.emplace(cu, cv);
            }
        }
    }


    
    cout << condensed_edges.size() << '\n';
    return 0;
}
