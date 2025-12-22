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
    }
    else{
        root->right = insert(root->right, val);
    }

    return root;
}

int DiamHeight(Node* root, int &diameter){
    if(!root){
        return 0;
    }

    int lft = DiamHeight(root->left, diameter);
    int rh = DiamHeight(root->right, diameter);

    diameter = max(diameter, lft+rh+1);
    return max(rh,lft)+1;
}

int Diameter(Node* root){
    int dia = 0;
    DiamHeight(root,dia);
    return dia;
}
int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        root = insert(root, x);
    }
    cout << Diameter(root) << endl;
    return 0;
}