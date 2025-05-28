#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("success.in");
    if (!fin) {
        cerr << "Error: success.in not found!" << endl;
        return 1;
    }

    ofstream fout("success.out");

    int n;
    fin >> n;
    if (n <= 0) {
        cerr << "Error: invalid n" << endl;
        return 1;
    }

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        fin >> p[i];
    }

    int i = n - 2;
    while (i >= 0 && p[i] >= p[i + 1]) {
        i--;
    }

    if (i == -1) {
        for (int j = 0; j < n; j++) {
            fout << j + 1 << " ";
        }
    } else {
        int j = n - 1;
        while (p[j] <= p[i]) {
            j--;
        }

        swap(p[i], p[j]);

        int l = i + 1, r = n - 1;
        while (l < r) {
            swap(p[l], p[r]);
            l++;
            r--;
        }

        for (int j = 0; j < n; j++) {
            fout << p[j] << " ";
        }
    }

    return 0;
}
