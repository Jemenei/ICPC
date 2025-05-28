#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("inverse.in");
    ofstream fout("inverse.out");

    int n;
    fin >> n;
    
    vector<int> p(n);
    vector<int> q(n);

    for (int i = 0; i < n; i++) {
        fin >> p[i];
        q[p[i] - 1] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        fout << q[i] << " ";
    }

    return 0;
}
