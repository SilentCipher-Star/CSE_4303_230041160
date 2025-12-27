#include<iostream>
#include<algorithm>
using namespace std;

struct Node{

    int data;
    Node* left;
    Node* right;
    Node* parent;
    int height;

    Node(int val){
        data = val;
        left = right = parent = NULL;
        height = 0;
    }
};

Node* root = NULL;

int height(Node* x){
    if(x == NULL){
        return -1;
    }else{
        return x->height;   
    }
}

void update_height(Node* x){
    while(x){
        int lh = height(x->left);
        int rh = height(x->right);
        x->height = max(lh,rh)+1;
        x = x->parent;
    }
}

int balance_factor(Node* node){
    return (height(node->left) - height(node->right));
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << "(" << balance_factor(root) << ")" << " ";
    inorder(root->right);
}
void insert(Node* &root, int x){
    Node* newnode = new Node(x);
    newnode->data = x;
    newnode->height = 0;
    if(root == NULL){
        root = newnode;
        return;
    }

    Node* temp = root;
    Node* target = NULL;

    while(temp){
        target = temp;
        if(x < temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    newnode->parent = target;
    if(x < target->data){
        target->left = newnode;
    }else{
        target->right = newnode;
    } 
    update_height(newnode);
}

void print_inorder(){
    inorder(root);
    cout << endl;
}
int main(){

    int n;
    while(cin >> n && n != -1){
        insert(root,n);
        print_inorder();

    }
    return 0;
}