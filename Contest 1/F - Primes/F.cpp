#include <iostream>
#include <vector>
using namespace std;


const int max_n = 1e7 + 1;
vector<int> prime_prefix(max_n, 0);


void sieve() {
    vector<bool> is_prime(max_n, true);
    is_prime[0] = is_prime[1] = false;
    
    for(int i = 2; i * i < max_n; i++) {
        if(is_prime[i]) {
            for(int j = i * i; j < max_n; j += i) {
                is_prime[j] = false;
            }
        }

    }

    for(int i = 1; i < max_n; i++) {
        prime_prefix[i] = prime_prefix[i - 1] + is_prime[i];
    }
}




int main() {
    sieve();
    int n, m;
    bool first = true;

    while (cin >> m >> n) {
        if(!first) {
            cout << "\n";
        }

        first = false;
        cout << prime_prefix[n] - prime_prefix[m - 1] << "\n";
    }
}