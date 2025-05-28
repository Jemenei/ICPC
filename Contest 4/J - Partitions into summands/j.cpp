#include <iostream>
#include <vector>

using namespace std;

void generate_brackets(int open, int close, string current) {
    if(open == 0 && close == 0) {
        cout << current << endl;
        return;
    }

    if(open > 0) {
        generate_brackets(open - 1, close, current + '(');
    }

    if(close > open) {
        generate_brackets(open, close - 1, current + ')');
    }
}


int main() {
    int n; cin >> n;
    generate_brackets(n, n, "");

    return 0;
}