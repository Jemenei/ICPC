#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;



int n, m;
vector<vector<int> > adj, rev_adj;
vector<int> disc, low, scc;
stack<int> st;
int timer_counter = 0;
int scc_count = 0;



void tarjanSCC(int u) {
    disc[u] = low[u] = ++timer_counter;
    st.push(u);


    for(int v : adj[u]) {
        if(disc[v] == -1) {
            tarjanSCC(v);
            low[u] = min(low[u], low[v]);
        } else if (scc[v] == -1) {
            low[u] = min(low[u], disc[v]);
        }
    }


    if(low[u] == disc[u]) {
        int w;
        do {
            w = st.top();
            st.pop();
            scc[w] = scc_count;
        } while (w != u);
        scc_count++;
    }
}



int main() {
    cin >> n >> m;
    adj.resize(n);
    rev_adj.resize(n);


    for(int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }


    disc.assign(n, -1);
    low.assign(n, -1);
    scc.assign(n, -1);


    for(int i = 0; i < n; ++i) {
        if(disc[i] == -1) {
            tarjanSCC(i);
        }
    }


    vector<vector<int> > scc_nodes(scc_count);
    for(int i = 0; i < n; ++i) {
        scc_nodes[scc[i]].push_back(i);
    }


    vector<vector<int> > scc_adj(scc_count);
    for(int u = 0; u < n; ++u) {
        for(int v : adj[u]) {
            if(scc[u] != scc[v]) {
                scc_adj[scc[u]].push_back(scc[v]);
            }
        }
    }


    set<int> terminal_sccs;
    for(int i = 0; i < scc_count; ++i) {
        if(scc_adj[i].empty()) {
            terminal_sccs.insert(i);
        }
    }


    vector<int> fire_stations;
    for(int scc_index : terminal_sccs) {
        if(!scc_nodes[scc_index].empty()) {
            fire_stations.push_back(scc_nodes[scc_index][0] + 1);
        }
    }

    
    cout << fire_stations.size() << endl;
    for(int i = 0; i < fire_stations.size(); ++i) {
        cout << fire_stations[i] << (i == fire_stations.size() - 1 ? "" : " ");
    }
    cout << endl;
    return 0;
}