#include <iostream>
#include <vector>

using namespace std;


int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}


int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}


int findCycleLength(vector<int>& p, vector<bool>& visited, int i) {
    int length = 0;
    while (!visited[i]) {
        visited[i] = true;
        i = p[i] - 1;
        length++;
    }
    return length;
}


int main() {
    int n; cin >> n;
    
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    vector<bool> visited(n, false);
    int order = 1;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            order = lcm(order, findCycleLength(p, visited, i));
        }
    }
    
    cout << order << endl;
    return 0;
}
