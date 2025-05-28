#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


typedef pair<int, int> s;




int main() {
    int n; cin >> n; 
    vector<s> seg(n);

    for(int i = 0; i < n; ++i) {
        cin >> seg[i].first >> seg[i].second;
    }


    sort(seg.begin(), seg.end(), [](s a, s b) {
        return a.second < b.second;
    });


    int count = 0;
    int last_end = -1e9;


    for(auto [l, r] : seg) {
        if(l >= last_end) {
            count++;
            last_end = r;
        }
    }
    cout << count << "\n";
    return 0;
}