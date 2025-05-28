#include <iostream>
#include <fstream>
#include <set>
#include <map>

using namespace std;

int main() {
    ifstream fin("exam.in");
    ofstream fout("exam.out");

    int n;
    fin >> n;

    set<int> freeTasks;
    map<int, int> busyTasks;

    for (int i = 1; i <= 100000; i++) {
        freeTasks.insert(i);
    }

    while (n--) {
        int a;
        fin >> a;

        if (a > 0) {
            auto it = freeTasks.lower_bound(a);
            int assignedTask = *it;
            fout << assignedTask << '\n';

            busyTasks[assignedTask] = 1;
            freeTasks.erase(it);
        } else {
            a = -a;
            freeTasks.insert(a);
            busyTasks.erase(a);
        }
    }

    fin.close();
    fout.close();

    return 0;
}
