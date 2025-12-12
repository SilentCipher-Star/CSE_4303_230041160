#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

void printlist(){
    if(head == NULL){
        cout << "Head=Null, Tail=Null, "<< endl;
        cout << "Head2Tail: Empty" << endl;
        cout << "Tail2Head: Empty" << endl;
        return;
    }
    cout << "Head=" << head->data << ", Tail=" << tail->data << ", ";
    cout << "Head2Tail: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "Tail2Head: ";
    temp = tail;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->prev != NULL) cout << " ";
        temp = temp->prev;
    }
    cout << endl;
}

void Insert_front(int key){
    Node* newnode = new Node();
    newnode->data = key;
    newnode->next = head;
    newnode->prev = NULL;

    if(head != NULL){
        head->prev = newnode;
    }
    head = newnode;
    if(tail == NULL){
        tail = newnode;
    }
    printlist();
}

void Insert_back(int key) {
    Node* newnode = new Node();
    newnode->data = key;
    newnode->next = NULL;
    newnode->prev = tail;

    if (tail != NULL)
        tail->next = newnode;
    tail = newnode;

    if (head == NULL)
        head = newnode;

    printlist();
}

void Insert_after_node (int key,  int v){
    Node* temp = head;
    while(temp != NULL && temp->data != v){
        temp = temp->next;
    }
    if(temp == NULL){
        cout << "Value not found" << endl;
        printlist();
        return;
    }

    Node* newnode = new Node();
    newnode->data =key;
    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL){
        temp->next->prev = newnode;
    }
    tail->next = newnode;
    if(temp == tail){
        tail = newnode;
    }
    printlist();
}

void Update_node (int key, int v){
    Node* temp = head;
    while(temp != NULL && temp->data != v){
        temp = temp->next;
    }
    if(temp == NULL){
        cout << "Value not found" << endl;
        printlist();
        return;
    }
    temp->data = key;
    printlist();
}

void Remove_head() {
    if (head == NULL) {
        cout << "Underflow" << endl;
        printlist();
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;

    delete temp;
    printlist();
}

void Remove_end() {
    if (tail == NULL) {
        cout << "Underflow" << endl;
        printlist();
        return;
    }

    Node* temp = tail;
    tail = tail->prev;

    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL;

    delete temp;
    printlist();
}

void Remove_element(int key) {
    if (head == NULL) {
        cout << "Value not found" << endl;
        printlist();
        return;
    }

    Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Value not found" << endl;
        printlist();
        return;
    }

    if (temp == head) {
        Remove_head();
        return;
    }
    if (temp == tail) {
        Remove_end();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
    printlist();
}

int main(){

    int choice;
    while (cin >> choice && choice != 8) {
        if (choice == 1) {
            int x; cin >> x;
            Insert_front(x);
        }
        else if (choice == 2) {
            int x; cin >> x;
            Insert_back(x);
        }
        else if (choice == 3) {
            int x, v; cin >> x >> v;
            Insert_after_node(x, v);
        }
        else if (choice == 4) {
            int x, v; cin >> x >> v;
            Update_node(x, v);
        }
        else if (choice == 5) {
            Remove_head();
        }
        else if (choice == 6) {
            int x; cin >> x;
            Remove_element(x);
        }
        else if (choice == 7) {
            Remove_end();
        }
    }

    cout << "Exit" << endl;
    return 0;
}