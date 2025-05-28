#include <bits/stdc++.h>
using namespace std;

#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

template<class T>
using pq    = priority_queue<T>;

template<class T>
using pqmin = priority_queue<T, vector<T>, greater<T>>;

typedef long long       ll;
typedef long double     ld;
typedef pair<int,int>   pii;

const char nl    = '\n';
const ld   eps   = 1e-9;
const ll   INF   = (ll)2e18 + 123;
const int  inf   = (int)1e9 + 123;
const int  mod   = (int)1e9 + 7;
const int  NMAX  = (int)1e6 + 123;

int n;

void solve() {
    cin >> n;
    vector<pii> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }

    sort(all(v));
    vector<ll> p(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        p[i + 1] = p[i] + v[i].second;
    }

    ll max_dif = 0;
    for (int i = 0; i < n; ++i) {
        max_dif = max(max_dif, (ll)v[i].first - p[i]);
    }

    for (int i = n - 1; i >= 0; --i) {
        if (p[i] < v[i].first) {
            for (int j = i; j < n; ++j) {
                if (v[j].second >= max_dif) {
                    cout << v[j].first;
                    return;
                }
            }
            break;
        }
    }

    cout << "gg";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    while (tt--) {
        solve();
        cout << nl;
    }
    return 0;
}
