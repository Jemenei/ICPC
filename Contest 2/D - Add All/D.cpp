#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;

int main() {
    int n; cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for(int i = 0; i < n; ++i) {
        ll x; cin >> x;
        pq.push(x);
    }


    ll total_cost = 0;
    while(pq.size() > 1) {
        ll first = pq.top(); pq.pop();
        ll second = pq.top(); pq.pop();
        ll sum = first + second;
        total_cost += sum;
        pq.push(sum);
    }

    cout << total_cost << "\n";
    return 0;
}