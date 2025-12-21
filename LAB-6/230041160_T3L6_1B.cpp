#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* root = NULL;

Node* insert(Node* root, int x){
    Node* newnode = new Node();
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    if(root == NULL){
        root = newnode;
        return root;
    }

    if(x < root->data){
        root->left = insert(root->left, x);
    }
    else{
        root->right = insert(root->right, x);
    }
    return root;
}

Node* lowest_common_ancestor(Node* root, int u, int v){
    if(root == NULL){
        return root;
    }

    if(u < root->data && v < root->data){
       return lowest_common_ancestor(root->left, u, v);
    }
    
    if(u > root->data && v > root->data){
        return lowest_common_ancestor(root->right, u, v);
    }
    return root;
}


int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        root = insert(root, val);
    }

    int q;
    cin >> q;
    while(q--){
        int u,v;
        cin >> u >> v;
        Node* lca = lowest_common_ancestor(root,u,v);
        if(lca) cout << lca->data << endl;
    }

    return 0;
}