#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;


const int inf = 1e9;



int main() {
    int n, e, t, m; cin >> n >> e >> t >> m;
    vector<vector<pair<int, int>> > rev_g(n + 1);

    for(int i = 0; i < m; ++i) {
        int a, b, time; cin >> a >> b >> time;
        rev_g[b].emplace_back(a, time);
    }

    vector<int> dist(n + 1, inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[e] = 0;
    pq.emplace(0, e);


    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u]) {
            continue;
        }

        for(auto [v, w] : rev_g[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }


    int count = 0;
    for(int i = 1; i <= n; ++i) {
        if(dist[i] <= t) {
            ++count;
        }
    }

    cout << count << '\n';
    return 0;

}