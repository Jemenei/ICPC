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

    int hanging_vertices = 0;
    for(int i = 0; i <= n; i++) {
        if(degrees[i] == 1) {
            hanging_vertices++;
        }
    }

    cout << hanging_vertices << endl;

    return 0;
}