#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


bool ternarySearch(const vector<int>& arr, int x) {
    int left = 0, right = arr.size() - 1;

    while(left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if(arr[mid1] == x || arr[mid2] == x) {
            return true;
        }
        
        if(x < arr[mid1]) {
            right = mid1 - 1;
        } else if (x > arr[mid2]) {
            left = mid2 + 1;
        } else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    return false;
}



int main() {
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while(q--) {
        int x; cin >> x;

        if(ternarySearch(arr, x)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}