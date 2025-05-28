#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int gcd(int a, int b) {
    while(b) {
        a %= b;
        swap(a, b);
    }
    return a;
}


int main() {
    int a, b; cin >> a >> b;
    int gcd_ab = gcd(a, b);

    vector<int> divisors;
    for(int i = 1; i * i <= gcd_ab; i++) {
        if(gcd_ab % i == 0) {
            divisors.push_back(i);
            if(i != gcd_ab / i) {
                divisors.push_back(gcd_ab / i);
            } 
        }
    }
    sort(divisors.begin(), divisors.end());


    int n; cin >> n;

    while (n--) {
        int low, high; cin >> low >> high;
        int answer = -1;

        for(int i = divisors.size() - 1; i >= 0; i--) {
            if(divisors[i] >= low && divisors[i] <= high) {
                answer = divisors[i];
                break;
            }
        }

        cout << answer << endl;
    }

    return 0;
}