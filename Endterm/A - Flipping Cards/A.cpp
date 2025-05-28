#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


const int maxn = 500005;

vector<int> adj[maxn];
vector<bool> used;
vector<int> match;



bool dfs(int u) {
    if(used[u]) {
        return false;
    }
    used[u] = true;


    for(int v : adj[u]) {
        if(match[v] == -1 || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}



bool solve_case() {
    int n; cin >> n;

    for(int i = 0; i < 2 * n; ++i) {
        adj[i].clear();
    }

    match.assign(2 * n + 2, -1);

    for(int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        adj[i].push_back(a);
        adj[i].push_back(b);
    }


    for(int i = 0; i < n; ++i) {
        used.assign(n, false);
        if(!dfs(i)) {
            return false;
        }
    }

    return true;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        if(solve_case()) {
            cout << "possible\n";
        } else {
            cout << "impossible\n";
        }
    }

    return 0;
}