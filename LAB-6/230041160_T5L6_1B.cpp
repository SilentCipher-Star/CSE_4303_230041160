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
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(Node* root, vector<int>&v){
    if(root == NULL) return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        root = insert(root, x);
    }
    vector<int>arr;
    inorder(root, arr);
    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;

        if(k > arr.size() || k <= 0){
            cout << "Invalid" << endl;
        }
        else{
            cout << arr[k-1] << endl;
        }
    }

    return 0;
}