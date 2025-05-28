#include <iostream>
#include <iomanip>

using namespace std;


int main() {
    int a, b; cin >> a >> b;
    double x_min = -a / 2.0;
    cout << fixed << setprecision(2) << x_min << endl;
    return 0;
}