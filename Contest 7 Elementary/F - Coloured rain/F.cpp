#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n; cin >> n;
    vector<vector<int> > adj(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    vector<int> colors(n);
    for(int i = 0; i < n; i++) {
        cin >> colors[i];
    }


    int bad_briges = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(adj[i][j] == 1 && colors[i] != colors[j]) {
                bad_briges++;
            }
        }
    }

    cout << bad_briges << endl;
    return 0;
}