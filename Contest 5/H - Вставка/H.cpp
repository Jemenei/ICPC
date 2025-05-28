#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int size;

    void build(int node, int start, int end, const deque<int>& arr) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid, arr);
            build(2 * node + 1, mid + 1, end, arr);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return INT_MAX;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return min(query(2 * node, start, mid, l, r),
                   query(2 * node + 1, mid + 1, end, l, r));
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2 * node, start, mid, idx, value);
            else
                update(2 * node + 1, mid + 1, end, idx, value);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

public:
    SegmentTree(int n) {
        size = n;
        tree.assign(4 * n, INT_MAX);
    }

    void build(const deque<int>& arr) {
        build(1, 0, size - 1, arr);
    }

    int query(int l, int r) {
        return query(1, 0, size - 1, l, r);
    }

    void update(int idx, int value) {
        update(1, 0, size - 1, idx, value);
    }
};

int main() {
    ifstream fin("rmq.in");
    ofstream fout("rmq.out");

    int n;
    fin >> n;

    deque<int> arr;
    SegmentTree segTree(200000);

    while (n--) {
        char op;
        fin >> op;
        if (op == '+') {
            int i, x;
            fin >> i >> x;
            if (i == 0)
                arr.push_front(x);
            else
                arr.insert(arr.begin() + i, x);
            segTree = SegmentTree(arr.size());
            segTree.build(arr);
        } else if (op == '?') {
            int l, r;
            fin >> l >> r;
            fout << segTree.query(l, r) << '\n';
        }
    }

    fin.close();
    fout.close();

    return 0;
}
