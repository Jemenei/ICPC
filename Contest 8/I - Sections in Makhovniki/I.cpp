#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> g[MAXN];
int indegree[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;


    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int v;
            cin >> v;
            --v; 
            g[v].push_back(i);  
            indegree[i]++;
        }
    }


    priority_queue<int> pq; 
    for (int i = 0; i < n; ++i)
        if (indegree[i] == 0)
            pq.push(i);

    vector<int> order;
    while (!pq.empty()) {
        int u = pq.top(); pq.pop();
        order.push_back(u);
        for (int v : g[u]) {
            indegree[v]--;
            if (indegree[v] == 0)
                pq.push(v);
        }
    }


    if ((int)order.size() != n) {
        cout << "-1\n";
        return 0;
    }


    reverse(order.begin(), order.end());


    for (int i = 0; i < n; ++i)
        cout << order[i] + 1 << " \n"[i == n - 1];

    return 0;
}
