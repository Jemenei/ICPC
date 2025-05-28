#include <iostream>
#include <vector>

using namespace std;



class SegmentTree {
private:
    int n;
    vector<long long> tree;


    void update(int node, int start, int end, int inx, long long value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (inx <= mid) {
                update(2 * node, start, mid, inx, value);
            } else {
                update(2 * node + 1, mid + 1, end, inx, value);
            }
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }


    long long query(int node, int start, int end, int left, int right) {
        if (left > end || right < start) {
            return 0;
        }
        if (left <= start && end <= right) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, left, right) +
               query(2 * node + 1, mid + 1, end, left, right);
    }


public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);
    }

    void update(int inx, long long value) {
        update(1, 1, n, inx, value);
    }

    long long query(int left, int right) {
        return query(1, 1, n, left, right);
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    SegmentTree segTree(n);

    while (k--) {
        char type; cin >> type;

        if (type == 'A') {
            int i; long long x; cin >> i >> x;
            segTree.update(i, x);
        } else if (type == 'Q') {
            int l, r; cin >> l >> r;
            cout << segTree.query(l, r) << '\n';
        }
    }

    return 0;
}
