#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* root = NULL;

Node* insert(Node* root, int val){
    if(!root){
        return new Node(val);
    }
    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void inorder(Node* root, vector<int>&v){
    if(!root) return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

Node* findNode(Node* root, int val){
    if(!root) return NULL;
    if(root->data == val) return root;
    if(val < root->data)
        return findNode(root->left, val);
    else
        return findNode(root->right, val);
}

bool printAncestor(Node* root, int val, vector<int>&v){
    if(!root) return false;
    if(root->data == val) return true;

    if(printAncestor(root->left,val, v) ||
       printAncestor(root->right, val, v)){
        v.push_back(root->data);
        return true;
    }
    return false;
}

void printDescendent(Node* node){
    if(!node){
        cout << "NULL\n";
        return;
    }

    vector<int>v;
    inorder(node,v);

    if(v.size() <= 1){
        cout << "NULL\n";
        return;
    }

    for(int i=0; i<v.size(); i++){
        if(v[i] != node->data)
            cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    int x;
    while(cin >> x && x != -1){
        root = insert(root, x);
    }

    vector<int>status;
    inorder(root, status);
    cout << "Status: ";
    for(int v : status) cout << v << " ";
    cout << endl;

    int q;
    cin >> q;

    while(q--){
        int key;
        cin >> key;

        cout << "\n" << key << "\n";

        vector<int>v;
        if(!printAncestor(root, key, v))
            cout << "NULL\n";
        else{
            for(int a : v) cout << a << " ";
            cout << endl;
        }

        Node* node = findNode(root, key);
        printDescendent(node);
    }
    return 0;
}
