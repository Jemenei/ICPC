#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n; cin >> n;
    vector<vector<int> > adj(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }


    vector<pair<int, int> > edges;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(adj[i][j] == 1) {
                edges.emplace_back(i + 1, j + 1);
            }
        }
    }


    for(const auto& edge : edges) {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}