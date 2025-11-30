#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->data) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    return 0;
}