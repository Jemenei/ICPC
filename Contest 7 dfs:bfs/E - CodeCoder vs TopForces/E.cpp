#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;



struct Citizen {
    int cc, tf, id;
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int n; cin >> n;
    vector<Citizen> citizens(n);
    for(int i = 0; i < n; i++) {
        cin >> citizens[i].cc >> citizens[i].tf;
        citizens[i].id = i;
    }


    vector<Citizen> sortedCC = citizens;
    sort(sortedCC.begin(), sortedCC.end(), [](const Citizen& a, const Citizen& b) {
        return a.cc < b.cc;
    });


    vector<Citizen> sortedTF = citizens;
    sort(sortedTF.begin(), sortedTF.end(), [](const Citizen& a, const Citizen& b) {
        return a.tf < b.tf;
    });


    vector<int> res(n, 0);
    for(int i = 0; i < n; i++) {
        Citizen current = citizens[i];

        auto it_cc = lower_bound(sortedCC.begin(), sortedCC.end(), current, [](const Citizen& a, const Citizen& b) {
            return a.cc < b.cc;
        });
        int count_cc = distance(sortedCC.begin(), it_cc);


        auto it_tf = lower_bound(sortedTF.begin(), sortedTF.end(), current, [](const Citizen& a, const Citizen& b) {
            return a.tf < b.tf;
        });
        int count_tf = distance(sortedTF.begin(), it_tf);

        set<int> reachable;
        for(int j = 0; j < count_cc; j++) {
            reachable.insert(sortedCC[j].id);
        }
        for(int j = 0; j < count_tf; j++) {
            reachable.insert(sortedTF[j].id);
        }

        reachable.erase(i);
        res[i] = reachable.size();
    }


    for(int num : res) {
        cout << num << '\n';
    }

    return 0;


}