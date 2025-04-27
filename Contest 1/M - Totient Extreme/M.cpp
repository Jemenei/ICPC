#include <iostream>
#include <vector>
using namespace std;


typedef long long ll;

const int N = 10001;
vector<int> phi(N);


void compute_phi() {
    for(int i = 0; i < N; i++) {
        phi[i] = i;
    }
    for(int i = 2; i < N; i++) {
        if(phi[i] == i) {
            for(int j = i; j < N; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
}


vector<ll> phi_sum(N);


void compute_phi_sum() {
    for(int i = 1; i < N; i++) {
        phi_sum[i] = phi_sum[i - 1] + phi[i];
    }
}



int main() {
    compute_phi();
    compute_phi_sum();

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        ll sum = phi_sum[n];
        cout << sum * sum << "\n";
    }
    return 0;
}