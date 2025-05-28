#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, m; cin >> n >> m;
    vector<int> degrees(n + 1, 0);

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        degrees[u]++; degrees[v]++;
    }

    for(int i = 1; i <= n; i++) {
        cout << degrees[i] << endl;
    }

    return 0;
}