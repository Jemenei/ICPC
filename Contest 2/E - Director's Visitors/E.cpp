#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Visitor {
    int start, end;
};


int to_minutes(const string& t) {
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3, 2));
    return h * 60 + m;
}


int main() {
    int n; cin >> n;
    vector<Visitor> visitors(n);


    for(int i = 0; i < n; ++i) {
        string t1, t2;
        cin >> t1 >> t2;
        visitors[i].start = to_minutes(t1);
        visitors[i].end = to_minutes(t2);
    }


    sort(visitors.begin(), visitors.end(), [](Visitor a, Visitor b) {
        return a.end < b.end;
    });


    int count = 0;
    int last_end = -1;

    for(auto v : visitors) {
        if(v.start >= last_end) {
            count++;
            last_end = v.end;
        }
    }
    
    cout << count << "\n";
    return 0;
}