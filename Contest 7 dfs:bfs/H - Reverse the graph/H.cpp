#include <iostream>
#include <vector>
#include <limits>
#include <deque>

using namespace std;

const int INF = 1e9;


int minReversedEdges(int n, int m, vector<pair<int, int>>& edges) {
    vector<vector<pair<int, int> > > graph(n + 1);

    for(auto [x, y] : edges) {
        graph[x].push_back({y, 0});
        graph[y].push_back({x, 1});
    }

    deque<int> d;
    vector<int> dist(n + 1, INF);
    dist[1] = 0;
    d.push_front(1);

    while(!d.empty()) {
        int node = d.front();
        d.pop_front();


        for (auto [neighbor, weight] : graph[node]) {
            if (dist[neighbor] > dist[node] + weight) {
                dist[neighbor] = dist[node] + weight;
                if (weight == 0) {
                    d.push_front(neighbor);
                } else {
                    d.push_back(neighbor);
                }
            }
        }
    }
    
    return (dist[n] == INF) ? -1 : dist[n];
}



int main() {
    int n, m; cin >> n >> m;
    vector<pair<int, int> > edges(m);

    for(int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }


    cout << minReversedEdges(n, m, edges) << endl;
    return 0;
}
