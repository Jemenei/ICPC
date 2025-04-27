#include <iostream>
using namespace std;

typedef long long ll;

ll safe_mul(ll a, ll b, ll mod) {
    ll result = 0;
    a %= mod;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result + a) % mod;
        }
        a = (a + a) % mod;
        b /= 2;
    }
    return result;
}

ll mod_pow(ll a, ll b, ll c) {
    ll res = 1;
    a = a % c;
    while (b > 0) {
        if (b % 2 == 1) {
            res = safe_mul(res, a, c);
        }
        a = safe_mul(a, a, c);
        b /= 2;
    }
    return res;
}

int main() {
    ll a, b, c;
    while (cin >> a >> b >> c) {
        cout << mod_pow(a, b, c) << "\n";
    }
    return 0;
}
