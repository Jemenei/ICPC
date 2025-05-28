#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;


const int inf = 1e9;



int main() {
    int n, m, s, d; cin >> n >> m >> s >> d;
    vector<vector<int> > g(n + 1);


    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    } 


    vector<vector<int> > dist(n + 1, vector<int>(2, inf));
    queue<tuple<int, int>> q;

    dist[s][0] = 0;
    q.emplace(s, 0);


    while(!q.empty()) {
        auto [u, parity] = q.front(); q.pop();
        for(int v : g[u]) {
            int new_parity = 1 - parity;
            if(dist[v][new_parity] == inf) {
                dist[v][new_parity] = dist[u][parity] + 1;
                q.emplace(v, new_parity);
            }
        }
    }


    if(dist[d][0] == inf) {
        cout << -1 << '\n';
    } else {
        cout << dist[d][0] << '\n';
    }

    return 0;
}

