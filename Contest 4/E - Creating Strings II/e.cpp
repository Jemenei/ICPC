#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e6 + 1;

long long fact[maxn], invFact[maxn];


long long power(long long a, long long b, long long mod) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % mod;  
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
} 


void preprocess() {
    fact[0] = invFact[0] = 1;
    for(int i = 1; i < maxn; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    
    invFact[maxn - 1] = power(fact[maxn - 1], mod - 2, mod);
    for(int i = maxn - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
    }
    invFact[0] = 1;
}


long long count_permutations(const string& s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    long long res = fact[s.size()];
    for(auto [ch, count] : freq) {
        res = (res * invFact[count]) % mod;
    }
    return res;
}


int main() {
    preprocess();

    string s; cin >> s;
    cout << count_permutations(s) << endl;
    return 0;
}