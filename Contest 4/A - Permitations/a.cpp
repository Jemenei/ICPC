#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("perm.in");
    ofstream fout("perm.out");

    int n;
    fin >> n;

    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
    }

    do {
        for (int i = 0; i < n; i++) {
            fout << perm[i] << " ";
        }
        fout << "\n";
    } while (next_permutation(perm.begin(), perm.end()));

    return 0;
}
