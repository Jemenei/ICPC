#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, m; cin >> n >> m;
    vector<vector<int> > adj_matrix(n, vector<int>(n, 0));

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj_matrix[u - 1][v - 1] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << adj_matrix[i][j];
            if(j != n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}