#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 
    cin >> n >> m;
    
    vector<int> diff(n + 1, 0);

    for (int i = 0; i < m; i++) {
        char type; 
        cin >> type;

        if (type == 'A') {
            int l, r, d; 
            cin >> l >> r >> d;
            diff[l] += d;
            if (r + 1 < n) {
                diff[r + 1] -= d;
            }
        } 
    }

    vector<int> arr(n, 0);
    arr[0] = diff[0];

    for (int i = 1; i < n; i++) {
        arr[i] = arr[i - 1] + diff[i];
    }

    cin.clear();  
    cin.seekg(0, ios::beg); 
    cin >> n >> m; 

    for (int i = 0; i < m; i++) {
        char type; 
        cin >> type;
        if (type == 'Q') {
            int ind; 
            cin >> ind;
            cout << arr[ind] << '\n';
        }
    }
    
    return 0;
}
