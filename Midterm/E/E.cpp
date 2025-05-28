#include <iostream>
#include <vector>

using namespace std;

int main() {
    int w, h; cin >> w >> h;
    vector<string> grid(h);

    for(int i = 0; i < h; i++) {
        cin >> grid[i];
    }
    int border = 0;


    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w - 1; j++) {
            if(grid[i][j] != grid[i][j + 1]) {
                border++;
            }
        }
    }


    for(int i = 0; i < h - 1; i++) {
        for(int j = 0; j < w; j++) {
            if(grid[i][j] != grid[i + 1][j]) {
                border++;
            }
        }
    }

    cout << border << endl;
    return 0;
}