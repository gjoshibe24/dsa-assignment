#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long val;
    Node* left;
    Node* right;
    Node(long long x): val(x), left(nullptr), right(nullptr) {}
};

Node* buildFromLevelOrder(const vector<long long>& a) {
    int n = (int)a.size();
    if (n == 0) return nullptr;
    vector<Node*> nodes(n, nullptr);
    for (int i = 0; i < n; ++i) {
        if (a[i] != LLONG_MIN) nodes[i] = new Node(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (!nodes[i]) continue;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < n) nodes[i]->left = nodes[l];
        if (r < n) nodes[i]->right = nodes[r];
    }
    return nodes[0];
}

bool isBSTUtil(Node* root, long long low, long long high) {
    if (!root) return true;
    if (root->val <= low || root->val >= high) return false;
    return isBSTUtil(root->left, low, root->val) && isBSTUtil(root->right, root->val, high);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a;
    a.reserve(n);
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        if (x == -1) a.push_back(LLONG_MIN);
        else a.push_back(x);
    }
    Node* root = buildFromLevelOrder(a);
    bool ans = isBSTUtil(root, LLONG_MIN, LLONG_MAX);
    cout << (ans ? "True" : "False") << '\n';
    return 0;
}