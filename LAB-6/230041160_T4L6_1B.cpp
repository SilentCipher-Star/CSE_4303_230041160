#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    int height;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        height = 0; // leaf node height
        left = right = nullptr;
    }
};

// Insert node into BST and update heights
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    int leftHeight = root->left ? root->left->height : -1;
    int rightHeight = root->right ? root->right->height : -1;
    root->height = 1 + max(leftHeight, rightHeight);
    return root;
}

// Inorder traversal with height
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << "(" << root->height << ") ";
    inorder(root->right);
}

// Find Lowest Common Ancestor (LCA)
Node* LCA(Node* root, int x, int y) {
    if (!root) return nullptr;
    if (root->data > x && root->data > y)
        return LCA(root->left, x, y);
    if (root->data < x && root->data < y)
        return LCA(root->right, x, y);
    return root; // this is LCA
}

// Find path from root to key
bool findPath(Node* root, int key, vector<int>& path) {
    if (!root) return false;
    path.push_back(root->data);
    if (root->data == key) return true;

    if ((root->data > key && findPath(root->left, key, path)) ||
        (root->data < key && findPath(root->right, key, path)))
        return true;

    path.pop_back();
    return false;
}

// Print path and length between two nodes
void printPathBetween(Node* root, int x, int y) {
    Node* lca = LCA(root, x, y);

    vector<int> path1, path2;
    findPath(lca, x, path1);
    findPath(lca, y, path2);

    reverse(path1.begin(), path1.end()); // x → LCA

    vector<int> fullPath = path1;
    for (int i = 1; i < path2.size(); i++) // LCA already included
        fullPath.push_back(path2[i]);

    for (int val : fullPath)
        cout << val << " ";
    cout << "\n" << fullPath.size() << "\n";
}

int main() {
    Node* root = nullptr;
    int val;

    // Insert values into BST
    while (cin >> val && val != -1) {
        root = insert(root, val);
    }

    cout << "Status: ";
    inorder(root);
    cout << "\n";

    // Handle queries
    int q;
    cin >> q; // number of queries
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        printPathBetween(root, x, y);
    }

    return 0;
}
