#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Node {
    int mostFreq, leftFreq, rightFreq, leftVal, rightVal;
};

vector<int> arr;
vector<Node> segTree;

Node merge(Node left, Node right) {
    Node res;
    res.leftVal = left.leftVal;
    res.rightVal = right.rightVal;
    res.leftFreq = left.leftFreq;
    res.rightFreq = right.rightFreq;

    if (left.leftVal == right.leftVal) {
        res.leftFreq += right.leftFreq;
    }
    if (left.rightVal == right.rightVal) {
        res.rightFreq += left.rightFreq;
    }

    res.mostFreq = max({left.mostFreq, right.mostFreq});

    if (left.rightVal == right.leftVal) {
        int mergedFreq = left.rightFreq + right.leftFreq;
        res.mostFreq = max(res.mostFreq, mergedFreq);
    }

    return res;
}

void build(int node, int start, int end) {
    if (start == end) {
        segTree[node] = {1, 1, 1, arr[start], arr[start]};
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    segTree[node] = merge(segTree[2 * node], segTree[2 * node + 1]);
}

Node query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return {0, 0, 0, 0, 0}; 
    }
    if (l <= start && end <= r) {
        return segTree[node];
    }
    int mid = (start + end) / 2;
    Node leftPart = query(2 * node, start, mid, l, r);
    Node rightPart = query(2 * node + 1, mid + 1, end, l, r);
    return merge(leftPart, rightPart);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n, q; cin >> n;
        if (n == 0) break;
        cin >> q;

        arr.resize(n);
        segTree.assign(4 * n, {0, 0, 0, 0, 0});

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        build(1, 0, n - 1);

        while (q--) {
            int i, j; cin >> i >> j;
            i--, j--;
            cout << query(1, 0, n - 1, i, j).mostFreq << '\n';
        }
    }

    return 0;
}
