#include <iostream>
using namespace std;

typedef long long ll;

ll fast_pow(ll x, ll n) {
    ll result = 1;
    while(n > 0) {
        if(n % 2 == 1) {
            result *= x;
        }
        x *= x;
        n /= 2;
    }
    return result;
}


int main() {
    ll x, n; cin >> x >> n;
    cout << fast_pow(x, n) << "\n";
    return 0;
}