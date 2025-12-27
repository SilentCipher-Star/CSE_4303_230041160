#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node* parent;
    int height;
    Node(int v){
        data = v;
        left = right = parent = NULL;
        height = 0;
    }
};

Node* root = NULL;

int height(Node* x){
    if(!x) return -1;
    return x->height;
}

int balance_factor(Node* x){
    return height(x->left) - height(x->right);
}

void update_height(Node* x){
    while(x){
        x->height = max(height(x->left), height(x->right)) + 1;
        x = x->parent;
    }
}

void inorder(Node* r){
    if(!r) return;
    inorder(r->left);
    cout << r->data << "(" << balance_factor(r) << ") ";
    inorder(r->right);
}

void print_avl(){
    inorder(root);
    cout << endl;
}

void right_rotate(Node* z){
    Node* y = z->left;
    Node* yR = y->right;
    y->parent = z->parent;

    if(z == root) root = y;
    else if(z == z->parent->left) z->parent->left = y;
    else z->parent->right = y;

    y->right = z;
    z->parent = y;
    z->left = yR;
    if(yR) yR->parent = z;

    update_height(z);
}

void left_rotate(Node* z){
    Node* y = z->right;
    Node* yL = y->left;
    y->parent = z->parent;

    if(z == root) root = y;
    else if(z == z->parent->left) z->parent->left = y;
    else z->parent->right = y;

    y->left = z;
    z->parent = y;
    z->right = yL;
    if(yL) yL->parent = z;

    update_height(z);
}

void Balance_node(Node* z){
    if(balance_factor(z) > 1){
        if(balance_factor(z->left) >= 0){
            cout << "LL case\n";
            right_rotate(z);
        }
        else{
            cout << "LR case\n";
            left_rotate(z->left);
            right_rotate(z);
        }
    }
    else if(balance_factor(z) < -1){
        if(balance_factor(z->right) <= 0){
            cout << "RR case\n";
            left_rotate(z);
        }
        else{
            cout << "RL case\n";
            right_rotate(z->right);
            left_rotate(z);
        }
    }
}

void insert(int x){
    Node* n = new Node(x);

    if(!root){
        root = n;
        print_avl();
        cout << "Balanced\nRoot=" << root->data << endl;
        return;
    }

    Node* t = root;
    Node* p = NULL;

    while(t){
        p = t;
        if(x < t->data) t = t->left;
        else t = t->right;
    }

    n->parent = p;
    if(x < p->data) p->left = n;
    else p->right = n;

    update_height(n);
    print_avl();

    Node* z = n->parent;
    while(z){
        if(abs(balance_factor(z)) > 1){
            cout << "Imbalance at node: " << z->data << endl;
            Balance_node(z);
            cout << "Status: ";
            print_avl();
            cout << "Root=" << root->data << endl;
            return;
        }
        z = z->parent;
    }

    cout << "Balanced\nRoot=" << root->data << endl;
}

Node* minvalue(Node* x){
    while(x->left) x = x->left;
    return x;
}

void Delete(int key){
    cout << "Delete " << key << endl;

    Node* t = root;
    while(t && t->data != key){
        if(key < t->data) t = t->left;
        else t = t->right;
    }

    if(!t){
        cout << "-1\n";
        return;
    }

    if(t->left && t->right){
        Node* s = minvalue(t->right);
        t->data = s->data;
        t = s;
    }

    Node* child = t->left ? t->left : t->right;

    if(!t->parent){
        root = child;
        if(child) child->parent = NULL;
    }
    else{
        if(t == t->parent->left) t->parent->left = child;
        else t->parent->right = child;
        if(child) child->parent = t->parent;
    }

    Node* z = t->parent;
    delete t;

    while(z){
        update_height(z);
        if(abs(balance_factor(z)) > 1){
            cout << "Imbalanced at node " << z->data << endl;
            Balance_node(z);
            print_avl();
            cout << "-1\nStatus: ";
            print_avl();
            return;
        }
        z = z->parent;
    }

    print_avl();
    cout << "Balanced\nRoot=" << root->data << endl;
}

int main(){
    int x;
    while(cin >> x && x != -1){
        insert(x);
    }

    while(cin >> x && x != -1){
        Delete(x);
    }

    cout << "Status: ";
    print_avl();
    return 0;
}
