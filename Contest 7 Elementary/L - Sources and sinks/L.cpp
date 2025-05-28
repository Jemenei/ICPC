#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
    int n; cin >> n;
    vector<vector<int> > adj_matrix(n, vector<int>(n));


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> adj_matrix[i][j];
        }
    }

    vector<int> sources; vector<int> sinks;
    for(int j = 0; j < n; j++) {
        bool isSource = true;
        for(int i = 0; i < n; i++) {
            if(adj_matrix[i][j] == 1) {
                isSource = false;
                break;
            }
        }

        if(isSource) {
            sources.push_back(j + 1);
        }
    }


    for(int i = 0; i < n; i++) {
        bool isSink = true;
        for(int j = 0; j < n; j++) {
            if(adj_matrix[i][j] == 1) {
                isSink = false;
                break;
            }
        }
        if(isSink) {
            sinks.push_back(i + 1);
        }
    }



    cout << sources.size() << " ";
    for(int s : sources) {
        cout << s << " ";
    }
    cout << endl;


    cout << sinks.size() << " ";
    for(int s : sinks) {
        cout << s << " ";
    }
    cout << endl;


    return 0;
}
