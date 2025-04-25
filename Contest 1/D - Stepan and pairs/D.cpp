#include <iostream>
using namespace std;


int main() {
    int n; cin >> n;
    long long rslt = n;

    for(int i = 2; i <= n; i++) {
        rslt += (n / i);
    }

    cout << rslt;
    return 0;
}