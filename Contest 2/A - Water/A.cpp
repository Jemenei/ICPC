#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    

    for(int &x : a) {
        cin >> x;
    }

    sort(a.begin(), a.end());

    int i = 0, j = n - 1;
    int trips = 0;


    while(i <= j) {
        if(a[j] > k) {
            cout << "Impossible\n";
            return 0;
        }
        if(i != j && a[i] + a[j] <= k) {
            i++; j--;
        } else {
            j--;
        }
        trips++;
    }


    cout << trips << "\n";
    return 0;
}