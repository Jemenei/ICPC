#include <iostream>
using namespace std;


long long w, h, n;

bool canFit(long long side) {
    return (side / w) * (side / h) >= n;
}


int main() {
    cin >> w >> h >> n;
    long long  left = 1, right = max(w, h) * n, mid, answer;

    while(left <= right) {
        mid = left + (right - left) / 2;
        if(canFit(mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }


    cout << answer << endl;
    return 0;
}