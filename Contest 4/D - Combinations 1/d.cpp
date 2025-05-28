#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n, k;
vector<int> combination;
ofstream fout("choose.out");

void generate(int start, int depth) {
    if (depth == k) {
        for (int num : combination) {
            fout << num << " ";
        }
        fout << "\n";
        return;
    }

    for (int i = start; i <= n; i++) {
        combination.push_back(i);
        generate(i + 1, depth + 1);
        combination.pop_back();
    }
}


int main() {
    ifstream fin("choose.in");
    fin >> n >> k;

    generate(1, 0);
    
    return 0;
}