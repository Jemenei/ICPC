#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 2e6 + 1;
long long fact[maxn + 1], inv_fact[maxn + 1];

long long power(long long a, long long b, long long mod) {
    long long res = 1;

    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }

    return res;

    // a -- основатель степени; b -- показатель; a^b;
    // Если b четное -> заменяем a^b на (a^2)^(b/2);
    // Если b нечетное -> умножаем res на a и уменьшаем b-1;
}


void precompute_fact() {
    fact[0] = 1;
    for(int i = 1; i <= maxn; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    inv_fact[maxn] = power(fact[maxn], mod - 2, mod);
    for(int i = maxn - 1; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    }
}


long long binomial_coefficient(int n, int k) {
    if (k > n || k < 0) {
        return 0;
    }
    return (((fact[n] * inv_fact[k]) % mod) * inv_fact[n - k]) % mod;
}


int main() {
    precompute_fact();

    int k; cin >> k;
    vector<int> c(k);

    for(int i = 0; i < k; i++) {
        cin >> c[i];
    } 

    long long ways = 1;
    int total_balls = 0;

    for(int i = 0; i < k; i++) {
        total_balls += c[i];
        ways = (ways * binomial_coefficient(total_balls - 1, c[i] - 1)) % mod;
    }

    cout << ways << endl;
    return 0;
}