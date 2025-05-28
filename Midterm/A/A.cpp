#include <iostream>
#include <vector>
#include <limits>

using namespace std;



int maxSubarraySum(int n, vector<int>& profits) {
    int maxSum = -1000000, currentSum = 0;

    for(int i = 0; i < n; i++) {
        currentSum = max(profits[i], currentSum + profits[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    int n; cin >> n;
    vector<int> profits(n);

    for(int i = 0; i < n; i++) {
        cin >> profits[i];
    }

    cout << maxSubarraySum(n, profits) << endl;
    return 0;
}