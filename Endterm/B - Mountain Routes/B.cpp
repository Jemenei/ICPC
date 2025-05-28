#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


const int maxn = 51;
const int maxd = 11;

vector<int> g[maxn];
int dp[maxn][maxd];
int b, d;



int count_paths(int node, int steps) {
    if(steps > d) {
        return 0;
    }

    if(node == b) {
        return 1;
    }


    int& res = dp[node][steps];
    if(res != -1){
        return res;
    }

    
    res = 0;
    for(int nei : g[node]) {
        res += count_paths(nei, steps + 1);
    }
    return res;
} 



int main() {
    int n, k, a; cin >> n >> k >> a >> b >> d;

    for(int i = 0; i < k; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }


    memset(dp, -1, sizeof(dp));
    cout << count_paths(a, 0) << '\n';

    return 0;
}