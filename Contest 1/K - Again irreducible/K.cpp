#include <iostream>
using namespace std;


typedef long long ll;

ll phi(ll n) {
    ll res = n;
    for(ll p = 2; p * p <= n; ++p) {
        if(n % p == 0) {
            while(n % p == 0) {
                n /= p;
            }
            res -= res / p;
        }
    }
    if(n > 1) {
        res -= res / n;
    }
    return res;
}



int main() {
    ll n;
    while(cin >> n && n != 0) {
        cout << phi(n) << "\n";
    }
    return 0;
}