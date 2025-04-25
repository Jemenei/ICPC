#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


const long long max_n = 1e12;
const int sqrt_max_n = 1000000;
vector<long long> almostPrimes;


void findAlmostPrimes() {
    vector<bool> isPrime(sqrt_max_n + 1, true);
    vector<long long> primes;

    for(long long i = 2; i <= sqrt_max_n; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(long long j = i * i; j <= sqrt_max_n; j+= i) {
                isPrime[j] = false;
            }
        }
    }


    for(long long p : primes) {
        long long power = p * p;
        while(power <= max_n) {
            almostPrimes.push_back(power);
            if(power > max_n / p) {
                break;
            }
            power *= p;
        }
    }

    sort(almostPrimes.begin(), almostPrimes.end());
}


int countAlmostPrimes(long long low, long long high) {
    return upper_bound(almostPrimes.begin(), almostPrimes.end(), high) - lower_bound(almostPrimes.begin(), almostPrimes.end(), low);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    findAlmostPrimes();

    int n; cin >> n;

    while(n--) {
        long long low, high; cin >> low >> high;
        cout << countAlmostPrimes(low, high) << "\n";
    }

    return 0;
}