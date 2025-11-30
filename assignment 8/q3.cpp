#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x): data(x), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->data) root->left = insertNode(root->left, x);
    else if (x > root->data) root->right = insertNode(root->right, x);
    return root;
}

Node* findMinNode(Node* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        } else if (!root->left) {
            Node* r = root->right;
            delete root;
            return r;
        } else if (!root->right) {
            Node* l = root->left;
            delete root;
            return l;
        } else {
            Node* succ = findMinNode(root->right);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1 + max(l, r);
}

int minDepth(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    return 1 + min(l, r);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int readInt() {
    int x;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid. Enter integer: ";
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Node* root = nullptr;
    while (true) {
        cout << "\n1. Insert (no duplicates)\n2. Delete\n3. Maximum depth\n4. Minimum depth\n5. In-order traversal\n0. Exit\nChoose: ";
        int ch = readInt();
        if (ch == 0) break;
        if (ch == 1) {
            cout << "Enter value to insert: ";
            int v = readInt();
            Node* found = root;
            bool exists = false;
            while (found) {
                if (v == found->data) { exists = true; break; }
                if (v < found->data) found = found->left;
                else found = found->right;
            }
            if (exists) cout << "Duplicate not allowed\n";
            else {
                root = insertNode(root, v);
                cout << "Inserted\n";
            }
        } else if (ch == 2) {
            cout << "Enter value to delete: ";
            int v = readInt();
            Node* before = root;
            bool exists = false;
            while (before) {
                if (v == before->data) { exists = true; break; }
                if (v < before->data) before = before->left;
                else before = before->right;
            }
            if (!exists) cout << "Value not found\n";
            else {
                root = deleteNode(root, v);
                cout << "Deleted (if existed)\n";
            }
        } else if (ch == 3) {
            cout << "Maximum depth: " << maxDepth(root) << "\n";
        } else if (ch == 4) {
            cout << "Minimum depth: " << minDepth(root) << "\n";
        } else if (ch == 5) {
            if (!root) cout << "(empty)\n";
            else { inorder(root); cout << "\n"; }
        } else {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}