#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    int n, m; cin >> n >> m;
    vector<vector<int> > adj(n + 1);

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;


    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }


    bool connected = true;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            connected = false;
            break;
        }
    }


    if(connected) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}