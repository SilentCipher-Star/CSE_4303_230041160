#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node* parent;

};

void insert(Node* &root,int x){
    Node* newnode = new Node();
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;
    if(root == NULL){
        root = newnode;
        return;
    }
    
    Node* temp = root;
    Node* target = NULL;
    while(temp != NULL){
        target = temp;
        if(newnode->data < temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }

    newnode->parent = target;
    if(newnode->data < target->data){
        target->left = newnode;

    }
    else{
        target->right = newnode;
    }

}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    if(root->parent == NULL){
        cout << root->data << "(null)";
    }
    else{
        cout << root->data << "("<<root->parent->data<< ")";
    }
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL){
        return;
    }
    if(root->parent == NULL){
        cout << root->data << "(null)";
    }
    else{
        cout << root->data << "(" << root->parent->data << ")";
    }
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    if(root->parent == NULL){
        cout << root->data << "(null)";
    }
    else{
        cout << root->data << "(" << root->parent->data << ")" ;
    }
}

void level_order(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    int level = 1;

    while(!q.empty()){
        int size = q.size();
        cout << "Level" << level << ":";
        while(size--){
            Node* temp = q.front();
            q.pop();

            if(temp->parent == NULL){
                cout << temp->data << "(null)";
            }
            else{
                cout << temp->data << "(" << temp->parent->data << ")";
            }

            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
        cout << endl;
        level++;
    }

}
int main(){

    Node* root = NULL;
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;

        insert(root,x);
        inorder(root);
        cout << endl;
    }

    cout << "\n1 Inorder:\n";
    inorder(root);
    cout << endl;

    cout << "\n2 Preorder:\n";
    preorder(root);
    cout << endl;

    cout << "\n3 Postorder:\n";
    postorder(root);
    cout << endl;

    cout << "\n4 Level order:\n";
    level_order(root);

    return 0;
}