#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


vector<int> bfs (int n, vector<vector<int>>& adj, int start, int end) {
    vector<int> dist(n + 1, -1);
    vector<int> parent(n + 1, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        for(int u : adj[v]) {
            if(dist[u] == -1) {
                dist[u] = dist[v] + 1;
                parent[u] = v;
                q.push(u);
            }
        }
    }

    if(dist[end] == -1) {
        return {};
    }

    vector<int> path;
    for(int v= end; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}




int main() {
    int n, m; cin >> n >> m;
    vector<vector<int> > adj(n + 1);
    int start, end; cin >> start >> end;

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<int> path = bfs(n, adj, start, end);
    if(path.empty()) {
        cout << -1 << endl;
    } else {
        cout << path.size() - 1 << endl;
        for(int p : path) {
            cout << p << " ";
        }
        cout << endl;
    }

    return 0;

}