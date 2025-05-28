#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



const int maxn = 1605;
vector<int> g[maxn], rev_g[maxn];
vector<int> order;
bool visited[maxn];
int c[maxn];



void dfs1(int v) {
    visited[v] = true;
    for(int u : g[v]) {
        if(!visited[u]) {
            dfs1(u);
        }
    }
    order.push_back(v);
}



void dfs2(int v, int label) {
    c[v] = label;
    for(int u : rev_g[v]) {
        if(c[u] == -1) {
            dfs2(u, label);
        }
    }
}



int main() {
    int n, m; cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        rev_g[v].push_back(u);
    }



    for(int i = 0; i < n; ++i) {
        if(!visited[i]){
            dfs1(i);
        }
    }



    fill(c, c + n, - 1);
    int label = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(c[order[i]] == -1) {
            dfs2(order[i], label++);
        }
    }



    if(label == 1) {
        cout << "1 0\n";
        return 0;
    }



    vector<int> in_deg(label, 0), out_deg(label, 0);
    for(int u = 0; u < n; u++) {
        for(int v : g[u]) {
            int cu = c[u], cv = c[v];
            if(cu != cv) {
                out_deg[cu]++;
                in_deg[cv]++;
            }
        }
    }


    int sources = count(in_deg.begin(), in_deg.end(), 0);
    int sinks = count(out_deg.begin(), out_deg.end(), 0);



    cout << sources << " " << max(sources, sinks) << '\n';
    return 0;


}