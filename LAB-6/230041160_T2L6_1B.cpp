#include<iostream>
using namespace std;

struct Node{
    int data;
    int height;
    Node* left;
    Node* right;
    Node* parent;
};

Node* root = NULL;

void insert(Node* &root, int x){
    Node* newnode = new Node();
    newnode->data = x;
    newnode->left = newnode->right = newnode->parent = NULL;
    newnode->height = 0;

    if(root == NULL){
        root = newnode;
        return;
    }

    Node* temp = root;
    Node* target = NULL;
    while(temp){
        target = temp;
        if(x < temp->data) temp = temp->left;
        else temp = temp->right;
    }

    newnode->parent = target;
    if(x < target->data) target->left = newnode;
    else target->right = newnode;

    while(target){
        int lh = (target->left ? target->left->height : -1);
        int rh = (target->right ? target->right->height : -1);
        int h = max(lh, rh) + 1;
        if(target->height == h) break;
        target->height = h;
        target = target->parent;
    }
}

void print_inorder(Node* root){
    if(!root) return;
    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);
}

Node* search(Node* root, int x){
    while(root){
        if(root->data == x) return root;
        else if(x < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

Node* maximum(Node* node){
    while(node->right) node = node->right;
    return node;
}

Node* minimum(Node* node){
    while(node->left) node = node->left;
    return node;
}

Node* inorder_predecessor(Node* curr){
    if(curr->left) return maximum(curr->left);
    Node* p = curr->parent;
    while(p && curr == p->left){
        curr = p;
        p = p->parent;
    }
    return p;
}

Node* inorder_successor(Node* curr){
    if(curr->right) return minimum(curr->right);
    Node* p = curr->parent;
    while(p && curr == p->right){
        curr = p;
        p = p->parent;
    }
    return p;
}

int main(){
    int choice, val;
    while(cin >> choice){
        switch(choice){
            case 1:{
                cin >> val;
                insert(root, val);
                print_inorder(root);
                cout << endl;
                break;
            }
            case 3:{
                cin >> val;
                Node* f = search(root, val);
                if(!f) cout << "Not found" << endl;
                else{
                    cout << "Present" << endl;
                    cout << "Parent(";
                    if(f->parent) cout << f->parent->data;
                    else cout << "Null";
                    cout << "), Left(";
                    if(f->left) cout << f->left->data;
                    else cout << "Null";
                    cout << "), Right(";
                    if(f->right) cout << f->right->data;
                    else cout << "Null";
                    cout << ")" << endl;
                }
                break;
            }
            case 4:{
                cin >> val;
                Node* f = search(root, val);
                if(f) cout << f->height << endl;
                else cout << "0" << endl;
                break;
            }
            case 5:{
                cin >> val;
                Node* f = search(root, val);
                if(!f) cout << "null null" << endl;
                else{
                    Node* pre = inorder_predecessor(f);
                    Node* succ = inorder_successor(f);
                    if(pre) cout << pre->data << " ";
                    else cout << "null ";
                    if(succ) cout << succ->data << endl;
                    else cout << "null" << endl;
                }
                break;
            }
            case 6:{
                cin >> val;
                Node* f = search(root, val);
                if(f){
                    Node* mn = minimum(f);
                    Node* mx = maximum(f);
                    cout << mn->data << " " << mx->data << endl;
                }
                else cout << "Node not found" << endl;
                break;
            }
            case 0: return 0;
        }
    }
}
