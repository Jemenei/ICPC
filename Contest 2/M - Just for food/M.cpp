#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<ll> food(n);
    for(int i = 0; i < n; i++) {
        cin >> food[i];
    }

    ll left = 0, right = 1e12;
    ll answer = 0;

    while(left <= right) {
        ll mid = (left + right) / 2;
        ll pieces = 0;
        
        for(int i = 0; i < n; i++) {
            pieces += min(food[i], mid);
        }

        if(pieces >= mid * m) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << "\n";

    return 0;
}