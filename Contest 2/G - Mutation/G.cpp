#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAX 100001
using namespace std;

vector<pair<int, int>> v;
int s[MAX], e[MAX];

int main() {
    int n;
    cin >> n;
    memset(s, -1, sizeof(s));
    memset(e, -1, sizeof(e));

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (s[x] == -1) s[x] = i;
        e[x] = i;
    }

    for (int i = 1; i <= n; ++i) {
        if (s[i] != -1) {
            v.push_back({s[i], e[i]});
        }
    }

    sort(v.begin(), v.end());

    int res = 0, i = 0;
    while (i < v.size()) {
        res++;
        int temp = v[i].second;
        i++;
        while (i < v.size() && v[i].first <= temp) {
            temp = max(temp, v[i].second);
            i++;
        }
    }

    cout << v.size() - res << "\n";
}
