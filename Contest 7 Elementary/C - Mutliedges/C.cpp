#include <iostream>
#include <set>

using namespace std;


int main() {
    int n, m; cin >> n >> m;
    set<pair<int, int> > edges;
    bool hasMultiEdges = false;

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        
        if(edges.count({u, v})) {
            hasMultiEdges = true;
        }

        edges.insert({u, v});
    }

    if(hasMultiEdges) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}