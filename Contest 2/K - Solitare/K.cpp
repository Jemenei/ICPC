#include <iostream>
#include <vector>
#include <set>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    
    for(int &x : a) {
        cin >> x;
    }
    
    multiset<int> piles;

    for(int x : a) {
        auto it = piles.lower_bound(x);
        if(it != piles.begin()) {
            --it;
            piles.erase(it);
        }
        piles.insert(x);
    }

    cout << piles.size() << "\n";
    return 0;
}