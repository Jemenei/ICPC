#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;



int n, m;
vector<vector<int> > g, rev_g;
vector<bool> used;
vector<int> o, c;
vector<set<int> > scc_graph;
vector<bool> reachable;
int scc_conut = 0;



void dfs1(int v) {
    used[v] = true;
    for(int to : g[v]) {
        if(!used[to]) {
            dfs1(to);
        }
    }
    o.push_back(v);
}



void dfs2(int v, int cl) {
    c[v] = cl;
    for(int to : rev_g[v]) {
        if(c[to] == -1) {
            dfs2(to, cl);
        }
    }
}



void dfs_scc(int u) {
    reachable[u] = true;
    for(int v : scc_graph[u]) {
        if(!reachable[v]) {
            dfs_scc(v);
        } 
    }
}



int main() {
    cin >> n >> m;
    g.resize(n);
    rev_g.resize(n);
    
    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        rev_g[b].push_back(a);
    }


    used.assign(n, false);
    for(int i = 0; i < n; ++i) {
        if(!used[i]) {
            dfs1(i);
        }
    }


    c.assign(n, -1);
    reverse(o.begin(), o.end());
    for(int v : o) {
        if(c[v] == -1) {
            dfs2(v, scc_conut++);
        }
    }


    scc_graph.resize(scc_conut);
    vector<int> in_deg(scc_conut, 0);
    for(int u = 0; u < n; ++u) {
        for(int v : g[u]) {
            int cu = c[u];
            int cv = c[v];
            if(cu != cv && !scc_graph[cu].count(cv)) {
                scc_graph[cu].insert(cv);
                in_deg[cv]++;
            }
        }
    }

    reachable.assign(scc_conut, false);
    int capital_scc = c[0];
    dfs_scc(capital_scc);

    int ans = 0;
    for(int i = 0; i < scc_conut; ++i) {
        if(!reachable[i] && in_deg[i] == 0) {
            ans++;
        } 
    }


    cout << ans << '\n';
    return 0;
}