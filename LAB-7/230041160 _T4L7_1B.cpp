#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
    int height;
    int size;
};

int getHeight(Node* node) {
    if (node == nullptr) return 1;
    return node->height;
}

int getSize(Node* node) {
    if (node == nullptr) return 0;
    return node->size;
}

void updateInfo(Node* node) {
    if (node != nullptr) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        node->size = 1 + getSize(node->left) + getSize(node->right);
    }
}

int getBalanceFactor(Node* node) {
    if (node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

void rightRotate(Node*& root, Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    x->parent = y->parent;
    y->parent = x;
    if (T2 != nullptr) T2->parent = y;

    if (x->parent == nullptr) {
        root = x;
    } else if (y == x->parent->right) {
        x->parent->right = x;
    } else {
        x->parent->left = x;
    }

    updateInfo(y);
    updateInfo(x);
}

void leftRotate(Node*& root, Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    y->parent = x->parent;
    x->parent = y;
    if (T2 != nullptr) T2->parent = x;

    if (y->parent == nullptr) {
        root = y;
    } else if (x == y->parent->left) {
        y->parent->left = y;
    } else {
        y->parent->right = y;
    }

    updateInfo(x);
    updateInfo(y);
}

void balanceNode(Node*& root, Node* node) {
    while (node != nullptr) {
        updateInfo(node);
        int balance = getBalanceFactor(node);
        Node* nextParent = node->parent;

        if (balance > 1) {
            if (getBalanceFactor(node->left) >= 0) {
                rightRotate(root, node);
            } else {
                leftRotate(root, node->left);
                rightRotate(root, node);
            }
            node = nextParent;
        } else if (balance < -1) {
            if (getBalanceFactor(node->right) <= 0) {
                leftRotate(root, node);
            } else {
                rightRotate(root, node->right);
                leftRotate(root, node);
            }
            node = nextParent;
        } else {
            node = node->parent;
        }
    }
}

void insertion(Node*& root, int key) {
    Node* newNode = new Node();
    newNode->data = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->parent = nullptr;
    newNode->height = 2;
    newNode->size = 1;

    if (root == nullptr) {
        root = newNode;
        return;
    }

    Node* current = root;
    Node* parent = nullptr;
    while (current != nullptr) {
        parent = current;
        if (key < current->data) current = current->left;
        else current = current->right;
    }

    newNode->parent = parent;
    if (key < parent->data) parent->left = newNode;
    else parent->right = newNode;

    balanceNode(root, newNode->parent);
}

int lowerCount(Node* root, int k) {
    if (root == nullptr) return 0;

    if (root->data == k) {
        return getSize(root->left);
    } else if (root->data > k) {
        return lowerCount(root->left, k);
    } else {
        return getSize(root->left) + 1 + lowerCount(root->right, k);
    }
}

int main() {
    Node* root = nullptr;
    int val;

    while (true) {
        cin >> val;
        if (val == -1) break;
        insertion(root, val);
    }

    while (true) {
        cin >> val;
        if (val == -1) break;
        cout << lowerCount(root, val) << endl;
    }

    return 0;
}
