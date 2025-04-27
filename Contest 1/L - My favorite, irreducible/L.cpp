#include <iostream>
#include <vector>
using namespace std;


typedef long long ll;

const int n = 10001;
vector<int> phi(n);


void compute_phi() {
    for(int i = 0; i < n; i++) {
        phi[i] = i;
    }
    for(int i = 2; i < n; i++) {
        if(phi[i] == i) {
            for(int j = i; j < n; j += i) {
                phi[j] -= phi[j] / i; 
            }
        }
    }
}



int main() {
    compute_phi();
    int n; cin >> n;

    ll ans = 0;
    for(int i = 2; i <= n; i++) {
        ans += phi[i];
    }

    cout << ans << "\n";
    return 0;
}