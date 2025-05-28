#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class SegmentTree {

private:
    int n;
    vector<int> minTree, maxTree;

    void build(int node, int start, int end, vector<int> &a) {
        if (start == end) {
            minTree[node] = maxTree[node] = a[start];
        } else {
            int mid = (start + end) / 2;

            build(2 * node, start, mid, a);
            build(2 * node + 1, mid + 1, end, a);

            minTree[node] = min(minTree[2 * node], minTree[2 * node + 1]);
            maxTree[node] = max(maxTree[2 * node], maxTree[2 * node + 1]);
        }
    }


    void update (int node, int start, int end, int inx, int value) {
        if (start == end) {
            minTree[node] = maxTree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if(inx <= mid) {
                update(2 * node, start, mid, inx, value);
            } else {
                update(2 * node + 1, mid + 1, end, inx, value);
            }

            minTree[node] = min(minTree[2 * node], minTree[2 * node + 2]);
            maxTree[node] = max(maxTree[2 * node], maxTree[2 * node + 1]);
        }
    }


    pair<int, int> query(int node, int start, int end, int left, int right) {
        if(right < start || left > end) {
            return {1e9, -1e9};
        }

        if(left <= start && end <= right) {
            return {minTree[node], maxTree[node]};
        }

        int mid = (start + end) / 2;
        auto leftRes = query(2 * node, start, mid, left, right);
        auto rightRes = query(2 * node + 1, mid + 1, end, left, right);

        return {min(leftRes.first, rightRes.first), (max(leftRes.second, rightRes.second))};
    }


public:
    SegmentTree(int size, vector<int> &a) {
        n = size;
        minTree.resize(4 * n);
        maxTree.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    void update(int inx, int value) {
        update(1, 0, n - 1, inx, value);
    }

    int query(int left, int right) {
        auto res = query(1, 0, n - 1, left, right);
        return res.second - res.first;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);



    int k; cin >> k;
    vector<int> a(100000);

    for(int i = 0; i < 100000; i++) {
        a[i] = (i * i % 12345) + (i * i * i % 23456);
    }

    SegmentTree segTree(100000, a);

    while(k--) {
        int x, y; cin >> x >> y;
        if(x > 0) {
            cout << segTree.query(x - 1, y - 1) << "\n";
        } else {
            segTree.update(-x - 1, y);
        }
    }
    return 0;
}