#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        ll r;
        cin >> n >> r;

        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<pair<ll,ll>> v;
        for (int i = 0; i < n; i++) {
            v.emplace_back(a[i], a[i] - b[i]);
        }
        sort(v.begin(), v.end());


        multiset<pair<ll,ll>> s;
        ll answer = 0;
        int idx = 0;

        while (true) {
            while (idx < n && v[idx].first <= r) {
                s.insert({ v[idx].second, v[idx].first });
                idx++;
            }

            if (s.empty()) break;


            auto it = s.begin();
            ll cost  = it->first;
            ll price = it->second;
            if (price > r) break;


            ll cnt = (r - price) / cost + 1;
            answer += cnt;
            r      -= cnt * cost;


            s.erase(it);
        }

        cout << answer << "\n";
    }

    return 0;
}
