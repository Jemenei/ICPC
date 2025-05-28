#include <iostream>
using namespace std;


int main() {
    int t; cin >> t;

    while(t--) {
        long long n, m; cin >> n >> m;
         
        if(n % (m + 1) == 0) {
            cout << "2";
        } else {
            cout << "1";
        }
    }

    cout << endl;
    return 0;
}