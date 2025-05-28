#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    freopen("stdin", "r", stdin);
    freopen("stdout", "w", stdout);

    int n, m, d; cin >> n >> m >> d;
    vector<int> elements;
    int first_mod = -1;

    for(int i = 0; i < n * m; i++) {
        int x; cin >> x;

        if(first_mod == -1) {
            first_mod = x % d;
        }

        if(x % d != first_mod) {
            cout << - 1 << endl;
            return 0;
        }

        elements.push_back(x);
    }

    sort(elements.begin(), elements.end());
    int mediana_value = elements[elements.size() / 2];


    long long steps = 0;
    for(int x : elements) {
        steps += abs(x - mediana_value) / d;
    }

    cout << steps << endl;
    return 0;
}