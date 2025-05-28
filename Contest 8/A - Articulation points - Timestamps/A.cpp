#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


const int maxn = 100;
int n, m;
int timer = 0;
int d[maxn], up[maxn];
int used[maxn];
int adj[maxn][maxn];



void dfs(int v, int p = -1) {
    used[v] = true;
    d[v] = up[v] = ++timer;

    for(int to = 0; to < n; to++) {
        if(adj[v][to]) {
            if(to == p) {
                continue;
            }
            if(used[to]) {
                up[v] = min(up[v], d[to]);
            } else {
                dfs(to, v);
                up[v] = min(up[v], up[to]);
            }
        }
    }
}



int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a][b] = adj[b][a] = 1;
    }


    int start; cin >> start; start--;
    dfs(start);

    for(int i = 0; i < n; ++i) {
        cout << d[i] << " " << up[i] << endl;
    }


    return 0;
}