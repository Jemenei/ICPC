#include <iostream>
#include <vector>
#include <random>

using namespace std;

struct Node {
    int val, priority, size;
    Node *left, *right;
    
    Node(int v) : val(v), priority(rand()), size(1), left(nullptr), right(nullptr) {}
};

int getSize(Node* t) {
    return t ? t->size : 0;
}

void updateSize(Node* t) {
    if (t) t->size = 1 + getSize(t->left) + getSize(t->right);
}

void split(Node* t, int key, Node*& l, Node*& r, int add = 0) {
    if (!t) {
        l = r = nullptr;
        return;
    }
    int curKey = add + getSize(t->left) + 1;
    if (key < curKey) {
        split(t->left, key, l, t->left, add);
        r = t;
    } else {
        split(t->right, key, t->right, r, curKey);
        l = t;
    }
    updateSize(t);
}

Node* merge(Node* l, Node* r) {
    if (!l || !r) return l ? l : r;
    if (l->priority > r->priority) {
        l->right = merge(l->right, r);
        updateSize(l);
        return l;
    } else {
        r->left = merge(l, r->left);
        updateSize(r);
        return r;
    }
}

void insert(Node*& root, int pos, int val) {
    Node *l, *r;
    split(root, pos, l, r);
    root = merge(merge(l, new Node(val)), r);
}

void update(Node*& root, int pos, int val) {
    Node *l, *m, *r;
    split(root, pos, l, r);
    split(r, 1, m, r);
    m->val = val;
    root = merge(merge(l, m), r);
}

int countGreaterEqual(Node* t, int c) {
    if (!t) return 0;
    if (t->val >= c) return 1 + getSize(t->right) + countGreaterEqual(t->left, c);
    return countGreaterEqual(t->right, c);
}

int rangeCount(Node* root, int a, int b, int c) {
    Node *l, *m, *r;
    split(root, a - 1, l, r);
    split(r, b - a + 1, m, r);
    int ans = countGreaterEqual(m, c);
    root = merge(merge(l, m), r);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    Node* root = nullptr;
    
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        insert(root, i, x);
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        int type, a, b, c;
        cin >> type >> a >> b;
        if (type == 0) {
            cin >> c;
            cout << rangeCount(root, a, b, c) << "\n";
        } else {
            update(root, a - 1, b);
        }
    }
    
    return 0;
}
