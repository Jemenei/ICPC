#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Job {
    int index;
    int time;
    int fine;
};


bool cmp(const Job &a, const Job &b) {
    long long lhs = 1LL * a.fine * b.time;
    long long rhs = 1LL * b.fine * a.time;
    if (lhs != rhs) {
        return lhs > rhs;
    }
    return a.index < b.index;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    bool first = true;
    while (cin >> n) {
        if (!first) cout << "\n";
        first = false;

        vector<Job> jobs(n);
        for (int i = 0; i < n; i++) {
            cin >> jobs[i].time >> jobs[i].fine;
            jobs[i].index = i + 1;
        }

        sort(jobs.begin(), jobs.end(), cmp);

        for (int i = 0; i < n; i++) {
            cout << jobs[i].index;
            if (i + 1 != n) cout << " ";
        }
        cout << "\n";
    }

    

    return 0;
}
