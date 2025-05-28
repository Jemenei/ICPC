#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


long long fact(int n) {
    long long res = 1;

    for(int i = 2; i <= n; i++) {
        res *= i;
    }

    return res;
}


int find_lexicographic_index(vector<int>& permutation) {
    int n = permutation.size();
    vector<int> available(n);

    for(int i = 0; i < n; i++) {
        available[i] = i + 1;
    }

    int ind = 0;
    for (int i = 0; i < n; i++) {
        int pos = find(available.begin(), available.end(), permutation[i]) - available.begin();
        ind += pos * fact(n - 1 - i);
        available.erase(available.begin() + pos);
    }
    
    return ind + 1;
}


int main() {
    int n; cin >> n;
    vector<int> permutation(n);

    for(int i = 0; i < n; i++) {
        cin >> permutation[i];
    }

    cout << find_lexicographic_index(permutation) << endl;
    return 0;
}