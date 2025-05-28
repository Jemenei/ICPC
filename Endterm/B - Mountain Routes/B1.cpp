#include <iostream>
#include <vector>

using namespace std;



const int maxn = 51;
vector<int> g[maxn];
int b, d;
int total_paths = 0;



void dfs(int node, int steps, vector<bool>& visited) {
    if(steps > d) {
        return;
    }
    if(node == b) {
        total_paths++;
        return;
    }

    for(int nei : g[node]) {
        if(!visited[nei]) {
            visited[nei] = true;
            dfs(nei, steps + 1, visited);
            visited[nei] = false;
        }
    }
}



int main() {
    int n, k, a; cin >> n >> k >> a >> b >> d;

    for(int i = 0; i < k; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }

    vector<bool> visited(n + 1, false);
    visited[a] = true;
    dfs(a, 0, visited);

    cout << total_paths << '\n';
    return 0;
}
