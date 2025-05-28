#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;


struct Box {
    double value, weight;
};


bool cmp(Box a, Box b) {
    return (a.value / a.weight) > (b.value / b.weight);
}



int main() {
    int n;
    double w;
    cin >> n >> w;
    vector<Box> boxes(n);

    for(int i = 0; i < n; ++i) {
        cin >> boxes[i].value >> boxes[i].weight;
    }

    sort(boxes.begin(), boxes.end(), cmp);
    
    double totalValue = 0.0;

    for(int i = 0; i < n && w > 0; ++i) {
        if(boxes[i].weight <= w) {
            totalValue += boxes[i].value;
            w -= boxes[i].weight;
        } else {
            totalValue += boxes[i].value * (w / boxes[i].weight);
            w = 0;
        }
    }

    cout << fixed << setprecision(3) << totalValue << "\n";
    return 0;
}