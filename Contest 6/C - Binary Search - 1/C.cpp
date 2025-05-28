#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n, q; cin >> n >> q;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while(q--) {
        int x; cin >> x;
        int left = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int right = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        cout << right - left << endl;
    }

    return 0;
}