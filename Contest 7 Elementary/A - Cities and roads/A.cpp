#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n; cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    int roads = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            if(j > i && matrix[i][j] == 1) {
                roads++;
            }
        }
    }

    cout << roads << endl;
    return 0;
}