#include<iostream>
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
    }else{
        root->right = insert(root->right, val);
    }
    return root;
}

void printleafnode(Node* root, bool &first){
    if(!root){
        return;
    }
    printleafnode(root->left, first);
    if(root->left == NULL && root->right == NULL){
        if(!first){
            cout << "," ;
        }
        cout << root->data ;
        first = false;
    }
    printleafnode(root->right, first);
    
}
int main(){

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        root = insert(root,x);
    }

    cout << "Leaf Node: "<< endl;
    bool first = true;
    printleafnode(root, first);
    cout << endl;
    return 0;
}