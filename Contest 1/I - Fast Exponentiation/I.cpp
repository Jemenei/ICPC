#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {
    int n; cin >> n;
    string b = "";


    while(n > 0) {
        b += (n % 2) + '0';
        n /= 2;
    }


    reverse(b.begin(), b.end());


    string res = "";
    for(char c : b) {
        if (c == '1') {
            res += "SX";
        } else {
            res += "S";
        }
    }

    res = res.substr(2);
    cout << res << "\n";

    return 0;
}