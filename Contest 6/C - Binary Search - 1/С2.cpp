#include <iostream>
#include <vector>

using namespace std;



int findFirst(const vector<int>& arr, int x) {
    int left = 0, right = arr.size() - 1, res = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            res = mid;
            right = mid - 1;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return res;
}



int findLast(const vector<int>& arr, int x) {
    int left = 0, right = arr.size() - 1, res = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            res = mid;
            left = mid + 1; 
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return res;
}



int main() {
    int n, q; cin >> n >> q;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while (q--) {
        int x; cin >> x;
        int first = findFirst(arr, x);

        if (first == -1) {
            cout << 0 << endl;
        } else {
            int last = findLast(arr, x);
            cout << last - first + 1 << endl;
        }
    }

    return 0;
}
