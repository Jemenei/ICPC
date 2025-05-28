#include <iostream>
using namespace std;


int main() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int o = 0;
    bool in_diff = false;


    for(int i = 0; i < n; ++i) {
        if(a[i] != b[i]) {
            if(!in_diff) {
                o++;
                in_diff = true;
            }
        } else {
            in_diff = false;
        }
    }

    cout << o << "\n";
    return 0;
}