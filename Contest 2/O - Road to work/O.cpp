#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int m = 2 * n;
    vector<ll> a(m);
    ll sum_all = 0;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        sum_all += a[i];
    }



    priority_queue<
        pair<ll,int>,
        vector<pair<ll,int>>,
        greater<pair<ll,int>>
    > heap;
    ll sum_down = 0;
    for (int i = 0; i < m; i++) {
        heap.emplace(a[i], i);
        sum_down += a[i];

        int cap = (i + 1) / 2;  
        if ((int)heap.size() > cap) {
            auto [val, idx] = heap.top();
            heap.pop();
            sum_down -= val;
        }
    }


    ll answer = sum_all - sum_down;
    cout << answer << "\n";


    vector<char> is_down(m, 0);
    while (!heap.empty()) {
        is_down[heap.top().second] = 1;
        heap.pop();
    }


    int y = 0;
    cout << "0 0\n";
    for (int i = 0; i < m; i++) {
        if (is_down[i]) {
            y -= 1;
        } else {
            y += 1;
        }
        cout << (i + 1) << " " << y << "\n";
    }

    return 0;
}
