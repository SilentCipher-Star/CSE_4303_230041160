#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int data;
    int height;
    Node *left;
    Node *right;
    Node *parent;

    Node(int val)
    {
        data = val;
        height = 0;
        left = right = parent = NULL;     
    }
};

Node *root = NULL;

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

void arrange_tree(Node *node)
{
    if (node == NULL)
        return;
    arrange_tree(node->left);
    cout << node->data << "(" << node->height << ")" << " ";
    arrange_tree(node->right);
}

int LCA(int a, int b)
{
    Node *curr = root;
    while (curr != NULL)
    {
        if (a < curr->data && b < curr->data)
            curr = curr->left;
        else if (a > curr->data && b > curr->data)
            curr = curr->right;
        else
            break;
    }
    if (curr != NULL)
        return curr->data;
    return -1;
}

Node *Search(Node *x, int key)
{
    while (x != NULL && x->data != key)
    {
        if (key < x->data){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }
    return x;
}

void print_route(Node *x, Node *y, Node *z)
{
    int count = 0;
    Node *temp = x;
    if (x != z)
    {
        while (temp != z)
        {
            cout << temp->data << " ";
            count++;
            temp = temp->parent;
        }
        cout << z->data << " ";
        count++;
    }

    if (y != z)
    {
        temp = z->right;
        while (temp != y)
        {
            if (temp->data < y->data)
            {
                cout << temp->data << " ";
                count++;
                temp = temp->right;
            }
            else
            {
                cout << temp->data << " ";
                count++;
                temp = temp->left;
            }
        }
        cout << y->data << " ";
        count++;
    }
    cout << "\n"
         << count << "\n";
}

int main()
{
    int n;
    while (cin >> n && n != -1)
    {
        insert(root,n);
    }
    cout << "Status: ";
    arrange_tree(root);
    cout << endl;

    while (true)
    {
        int a, b;
        cin >> a >> b;
        int count = 0;
        int c = LCA(a, b);
        Node *x = Search(root, a);
        Node *y = Search(root, b);
        Node *z = Search(root, c);
        print_route(x, y, z);
        cout << endl;
        // cout << "\n" << count << endl;
    }
    return 0;
}