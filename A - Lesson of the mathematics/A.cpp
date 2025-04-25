#include <iostream>
#include <map>

using namespace std;

int main() {
    int n; cin >> n;
    map<int, int> f;

    for(int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            f[i]++;
            n /= i;
        }
    }


    if (n > 1) {
        f[n]++;
    }

    bool first = true;
    for(auto [prime, power] : f) {
        if (!first) cout << "*";
        first = false;
        cout << prime;
        if(power > 1) cout << "^" << power;
    }
    return 0;
}