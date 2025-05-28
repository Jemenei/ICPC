#include <iostream>
#include <vector>

using namespace std;



int main() {
    int n; cin >> n;
    vector<vector<int> > matrix(n, vector<int>(n));
    int edges = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j] == 1) {
                edges++;
            }
        }
    }

    cout << edges << endl;
    return 0;
}