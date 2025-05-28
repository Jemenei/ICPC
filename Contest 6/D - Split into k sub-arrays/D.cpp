#include <iostream>
#include <vector>

using namespace std;

bool canSplit(const vector<int>& arr, int k, long long maxSum) {
    int count = 1;
    long long currentSum = 0;

    for(int num : arr) {
        if(currentSum + num > maxSum) {
            count++;
            currentSum = num;

            if(count > k) {
                return false;
            } 
        } else {
            currentSum += num;
        }
    }
    return true;
}



int main() {
    int n, k; cin >> n >> k;
    vector<int> arr(n);

    long long left = 0, right = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        left = max(left, (long long)arr[i]);
        right += arr[i];
    }

    
    while (left < right) {
        long long mid = left + (right - left) / 2;
        if(canSplit(arr, k, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }


    cout << left << endl;
    return 0;
}