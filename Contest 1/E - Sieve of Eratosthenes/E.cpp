#include <iostream>
using namespace std;


bool is_prime(int x) {
    if(x < 2) {
        return false;
    }

    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            return false;
        } 
    }
    return true;
}


int main() {
    int a, b; cin >> a >> b;
    bool first = true;


    for(int i = a; i <= b; i++) {
        if(is_prime(i)) {
            if(!first) {
                cout << " ";
            }
            cout << i;
            first = false;
            
        }
    }
    cout << endl;
    return 0;
}
