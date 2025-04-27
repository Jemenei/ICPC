#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;



typedef long long ll;
vector<ll> almost_primes;


void precompute() {
    const int lim = 1e6 + 1;
    vector<bool> is_prime(lim, true);

    for(int i = 2; i * i < lim; ++i) {
        if(is_prime[i]) {
            for(int j = i * i; j < lim; j += i) {
                is_prime[j] = false;
            }
        }
    }


    for(int i = 2; i < lim; ++i) {
        if(is_prime[i]) {
            ll x = (ll)i * i;
            while (x <= 1e12) {
                almost_primes.push_back(x);
                x *= i;
            }
        }
    }
    sort(almost_primes.begin(), almost_primes.end());
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();

    int n; cin >> n;

    while(n--) {
        ll low, high;
        cin >> low >> high;
        auto left = lower_bound(almost_primes.begin(), almost_primes.end(), low);
        auto right = upper_bound(almost_primes.begin(), almost_primes.end(), high);

        cout << right - left << "\n";
    }
    return 0;
}
