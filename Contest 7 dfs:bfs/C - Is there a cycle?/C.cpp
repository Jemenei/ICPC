#include <iostream>
#include <vector>

using namespace std;


bool dfs(int v, vector<vector<int> >& graph, vector<int>& visited) {
    visited[v] = 1;
    for(int u = 0; u < graph.size(); u++) {
        if(graph[v][u]) {
            if(visited[u] == 1) {
                return true;
            }
            if(visited[u] == 0 && dfs(u, graph, visited)) {
                return true;
            }
        }
    }
    visited[v] = 2;
    return false;
}


int main() {
    int n; cin >> n;
    vector<vector<int> > graph(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }


    vector<int> visited(n, 0);
    for(int i = 0; i < n; i++) {
        if(visited[i] == 0 && dfs(i, graph, visited)) {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}