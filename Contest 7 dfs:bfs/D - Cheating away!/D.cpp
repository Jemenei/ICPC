#include <iostream>
#include <vector>
#include <queue>

using namespace std;



bool isBipartite(vector<vector<int> >& adj, int n) {
    vector<int> color(n + 1, -1);
    for(int i = 1; i <= n; i++) {
        if(color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while(!q.empty()) {
                int u = q.front();
                q.pop();

                for(int v : adj[u]) {
                    if(color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}



int main() {
    int n, m; cin >> n >> m;
    vector<vector<int> > adj(n + 1);


    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    if(isBipartite(adj, n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }


    return 0;
}