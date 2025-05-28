#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;



struct Node {
    int max1, max2;
};



class SegmentTree {
public:
    vector<Node> tree;
    vector<int> arr;
    int n;



    Node Merge(Node left, Node right) {
        vector<int> vals = {left.max1, left.max2, right.max1, right.max2};
        sort(vals.rbegin(), vals.rend());
        return {vals[0], vals[1]};
    }



    void Build(int v, int tl, int tr) {
        if(tl == tr) {
            tree[v] = {arr[tl], INT_MIN};
        } else {
            int tm = (tl + tr) / 2;
            Build(v * 2, tl, tm);
            Build(v * 2 + 1, tm + 1, tr);
            tree[v] = Merge(tree[v * 2], tree[v * 2 + 1]);
        }
    }



    void Update(int v, int tl, int tr, int pos, int new_val) {
        if(tl == tr) {
            tree[v] = {new_val, INT_MIN}; 
        } else {
            int tm = (tl + tr) / 2;
            if(pos <= tm) {
                Update(v * 2, tl, tm, pos, new_val);
            } else {
                Update(v * 2 + 1, tm + 1, tr, pos, new_val);
            }
            tree[v] = Merge(tree[v * 2], tree[v * 2 + 1]);
        }
    }



    Node Query(int v, int tl, int tr, int l, int r) {
        if(l > r) {
            return {INT_MIN, INT_MIN};
        }

        if(tl == l && tr == r) {
            return tree[v];
        }

        int tm = (tl + tr) / 2;
        Node leftPart = Query(v * 2, tl, tm, l, min(r, tm));
        Node rightPart = Query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);

        return Merge(leftPart, rightPart);

    }



public: 
    SegmentTree(const vector<int>& inputArr) {
        arr = inputArr;
        n = arr.size();
        tree.resize(4 * n);
        Build(1, 0, n - 1);
    }



    void Update(int pos, int new_val) {
        Update(1, 0, n - 1, pos, new_val);
    }



    int getMaxSum(int l, int r) {
        Node res = Query(1, 0, n - 1, l, r);
        return res.max1 + res.max2;
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> arr(n);


    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SegmentTree st(arr);


    int q; cin >> q;
    while(q--) {
        char type; cin >> type;
        if(type == 'U') {
            int i, x; cin >> i >> x;
            st.Update(i - 1, x);
        } else if (type == 'Q') {
            int x, y; cin >> x >> y;
            cout << st.getMaxSum(x - 1, y - 1) << "\n";
        }
    }
    return 0;
}