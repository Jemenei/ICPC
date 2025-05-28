#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


using ll = long long;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(2 * n);
    
    for(int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }

    int best_place = n, worst_place = 1;

    for(int i = 1; i < 2 * n; i++) {
        vector<int> others;
        for(int j = 0; j < 2 * n; j++) {
            if(j != 0 && j != i) {
                others.push_back(a[j]);
            }
        }
        double my_team = (a[0] + a[i]) / 2.0;



        sort(others.begin(), others.end());
        int cnt = 0;
        for(int l = 0, r = others.size() - 1; l < r; l += 1, r -= 1) {
            double team_rating = (others[i] + others[r]) / 2.0;
            if(team_rating > my_team) {
                cnt++;
            }
        }
        best_place = min(best_place, cnt + 1);



        sort(others.rbegin(), others.rend());
        cnt = 0;
        for(int l = 0, r = others.size() - 1; l < r; l +=1, r-= 1) {
            double team_rating = (others[l] + others[r]) / 2.0;
            if(team_rating > my_team) {
                cnt++;
            }
        }
        worst_place = max(worst_place, cnt + 1);
    }


    cout << best_place << " " << worst_place << "\n";

    return 0;




    
}