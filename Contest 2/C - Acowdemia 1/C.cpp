#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



typedef long long ll;

bool can_achieve_h(const vector<int>& c, int l, int h) {
    int needed = 0;
    for(int citations : c) {
        if(citations >= h) {
            continue;
        } else if (citations + 1 >= h) {
            if (l >= 1) {
                needed++;
            }
        }
    }
    return (count_if(c.begin(), c.end(), [h](int x) { return x >= h; }) + min(l, needed)) >= h;
}



int main() {
    int n, l; cin >> n >> l;
    vector<int> c(n);
    for(int& x : c) {
        cin >> x;
    }

    sort(c.begin(), c.end(), greater<int>());


    int low = 0, high = n, ans = 0;
    while(low <= high) {
        int mid = (low + high) / 2;
        int cnt = 0, extra = l;
        for(int i = 0; i < n; i++) {
            if(c[i] >= mid) {
                cnt++;
            } else if (c[i] + 1 >= mid && extra > 0) {
                cnt++; extra--;
            }
        }
        if (cnt >= mid) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}