#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50005;

int par[MAXN], dsu_2ecc[MAXN], dsu_cc[MAXN], dsu_cc_size[MAXN], bridges;
int last_visit[MAXN], lca_iteration = 0;
int n;

int find_2ecc(int v) {
    if (v == -1) return -1;
    if (v == dsu_2ecc[v]) return v;
    return dsu_2ecc[v] = find_2ecc(dsu_2ecc[v]);
}

int find_cc(int v) {
    v = find_2ecc(v);
    if (v == dsu_cc[v]) return v;
    return dsu_cc[v] = find_cc(dsu_cc[v]);
}

void make_root(int v) {
    v = find_2ecc(v);
    int root = v, child = -1;
    while (v != -1) {
        int p = find_2ecc(par[v]);
        par[v] = child;
        dsu_cc[v] = root;
        child = v;
        v = p;
    }
    dsu_cc_size[root] = dsu_cc_size[child];
}

void merge_path(int u, int v) {
    ++lca_iteration;
    vector<int> path_u, path_v;
    int lca = -1;

    while (true) {
        if (u != -1) {
            u = find_2ecc(u);
            path_u.push_back(u);
            if (last_visit[u] == lca_iteration) {
                lca = u;
                break;
            }
            last_visit[u] = lca_iteration;
            u = par[u];
        }
        if (v != -1) {
            v = find_2ecc(v);
            path_v.push_back(v);
            if (last_visit[v] == lca_iteration) {
                lca = v;
                break;
            }
            last_visit[v] = lca_iteration;
            v = par[v];
        }
    }

    for (int x : path_u) {
        dsu_2ecc[x] = lca;
        if (x == lca) break;
        --bridges;
    }
    for (int x : path_v) {
        dsu_2ecc[x] = lca;
        if (x == lca) break;
        --bridges;
    }
}

void add_edge(int u, int v) {
    u = find_2ecc(u);
    v = find_2ecc(v);

    if (u == v) return;

    int cu = find_cc(u), cv = find_cc(v);
    if (cu != cv) {
        ++bridges;
        if (dsu_cc_size[cu] > dsu_cc_size[cv]) {
            swap(u, v);
            swap(cu, cv);
        }
        make_root(u);
        par[u] = v;
        dsu_cc[u] = v;
        dsu_cc_size[cv] += dsu_cc_size[u];
    } else {
        merge_path(u, v);
    }
}

void init(int N) {
    n = N;
    bridges = 0;
    for (int i = 0; i < n; ++i) {
        dsu_2ecc[i] = i;
        dsu_cc[i] = i;
        dsu_cc_size[i] = 1;
        par[i] = -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        init(N);
        while (M--) {
            int u, v;
            cin >> u >> v;
            add_edge(u, v);
            cout << bridges << '\n';
        }
    }

    return 0;
}
