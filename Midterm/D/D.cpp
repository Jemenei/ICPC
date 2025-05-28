#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <cmath>

using namespace std;


struct Part {
    string input, output;
    int time;
}


int findMinDiff(int target, const string& last, vector<Part>& parts) {
    unordered_map<string, vector<pair<string, int>>> graph;
    for (const auto& part : parts) {
        graph[part.input].push_back({part.output, part.time});
    }
    
    queue<pair<int, string>> q;
    unordered_map<string, unordered_map<int, bool>> visited;
    int min_diff = numeric_limits<int>::max();
    
    for (const auto& [start, _] : graph) {
        q.push({0, start});
        visited[start][0] = true;
    }
    
    while (!q.empty()) {
        auto [cur_time, cur_energy] = q.front();
        q.pop();
        
        if (cur_energy == last) {
            min_diff = min(min_diff, abs(target - cur_time));
        }
        
        for (auto& [next_energy, time] : graph[cur_energy]) {
            int new_time = cur_time + time;
            if (new_time <= target + min_diff && !visited[next_energy][new_time]) {
                visited[next_energy][new_time] = true;
                q.push({new_time, next_energy});
            }
        }
    }
    
    return min_diff;
}


int main() {
    int n, target;
    string last;
    cin >> n >> target >> last;

    vector<Part> parts(n);
    for(int i = 0; i < n; i++) {
        cin >> parts[i].input >> parts[i].output >> parts[i].time;
    }

    cout << findMinDiff(target, last, parts) << endl;
    return 0;
}