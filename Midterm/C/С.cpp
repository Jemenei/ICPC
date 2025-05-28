#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxElegantSum(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    vector<int> perm;
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        if (right > left) perm.push_back(arr[right--]);
        if (left <= right) perm.push_back(arr[left++]);
    }

    int sum = 0;
    for (int i = 1; i < perm.size(); i++) {
        sum += abs(perm[i] - perm[i - 1]);
    }

    return sum;
}

int main() {
    int t; cin >> t;

    for (int caseNum = 1; caseNum <= t; caseNum++) {
        int n; cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int result = maxElegantSum(arr);
        cout << "Case " << caseNum << ": " << result << endl;
    }

    return 0;
}
