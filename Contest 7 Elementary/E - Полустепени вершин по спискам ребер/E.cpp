#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, m; cin >> n >> m;
    vector<int> in_degree(n + 1, 0);
    vector<int> out_degree(n + 1, 0);

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        out_degree[u]++; in_degree[v]++;
    }

    for(int i = 1; i <= n; i++) {
        cout << in_degree[i] << " " << out_degree[i] << endl;
    }


    return 0;
}