#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x): data(x), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->data) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}

Node* recursiveSearch(Node* root, int key) {
    if (!root) return nullptr;
    if (root->data == key) return root;
    if (key < root->data) return recursiveSearch(root->left, key);
    return recursiveSearch(root->right, key);
}

Node* iterativeSearch(Node* root, int key) {
    Node* cur = root;
    while (cur) {
        if (cur->data == key) return cur;
        if (key < cur->data) cur = cur->left;
        else cur = cur->right;
    }
    return nullptr;
}

Node* minimum(Node* root) {
    if (!root) return nullptr;
    Node* cur = root;
    while (cur->left) cur = cur->left;
    return cur;
}

Node* maximum(Node* root) {
    if (!root) return nullptr;
    Node* cur = root;
    while (cur->right) cur = cur->right;
    return cur;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* target = iterativeSearch(root, key);
    if (!target) return nullptr;
    if (target->right) return minimum(target->right);
    Node* succ = nullptr;
    Node* cur = root;
    while (cur) {
        if (target->data < cur->data) {
            succ = cur;
            cur = cur->left;
        } else if (target->data > cur->data) {
            cur = cur->right;
        } else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, int key) {
    Node* target = iterativeSearch(root, key);
    if (!target) return nullptr;
    if (target->left) return maximum(target->left);
    Node* pred = nullptr;
    Node* cur = root;
    while (cur) {
        if (target->data > cur->data) {
            pred = cur;
            cur = cur->right;
        } else if (target->data < cur->data) {
            cur = cur->left;
        } else break;
    }
    return pred;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        root = insert(root, x);
    }

    int key;
    cin >> key;

    Node* rres = recursiveSearch(root, key);
    cout << (rres ? "Found (Recursive)\n" : "Not Found (Recursive)\n");

    Node* ires = iterativeSearch(root, key);
    cout << (ires ? "Found (Iterative)\n" : "Not Found (Iterative)\n");

    Node* mn = minimum(root);
    if (mn) cout << "Minimum: " << mn->data << '\n';
    else cout << "Tree is empty\n";

    Node* mx = maximum(root);
    if (mx) cout << "Maximum: " << mx->data << '\n';
    else cout << "Tree is empty\n";

    Node* succ = inorderSuccessor(root, key);
    if (succ) cout << "In-order Successor of " << key << ": " << succ->data << '\n';
    else cout << "In-order Successor of " << key << ": NULL\n";

    Node* pred = inorderPredecessor(root, key);
    if (pred) cout << "In-order Predecessor of " << key << ": " << pred->data << '\n';
    else cout << "In-order Predecessor of " << key << ": NULL\n";

    return 0;
}