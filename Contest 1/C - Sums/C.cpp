#include <iostream>
using namespace std;

void solve(int n) {
    for(int k = 2; k * (k + 1) / 2 <= n; k++) {
        int num = n - k * (k - 1) / 2;
        if(num % k == 0) {
            int a = num / k;
            cout << n << " = ";
            for(int i = 0; i < k; i++) {
                if(i > 0) {
                    cout << " + ";
                }
                cout << (a + i);
            }
            cout << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    int t, n; cin >> t;
    
    while(t--) {
        cin >> n;
        solve(n);
    }
    return 0;
}