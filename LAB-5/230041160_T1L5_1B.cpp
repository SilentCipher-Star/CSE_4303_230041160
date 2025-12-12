#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void printlist(){
    if(head == NULL){
        cout << "Head=Null, Tail=Null, Empty" << endl;
        return;
    }

    cout << "Head=" << head->data << ", Tail=" << tail->data << ", ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " ";
        temp = temp->next;
    }
    cout << endl;
    
}

void Insert_front(int key){

    Node* newnode = new Node();
    newnode->data = key;
    newnode->next = head;
    head = newnode;
    if(tail == NULL){
        tail = newnode;
    }
    printlist();

}

void Insert_back(int key){
    Node* newnode = new Node();
    newnode->data = key;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
        tail = newnode;
    }else{
        tail->next = newnode;
        tail = newnode;
    }
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
    newnode->data = key;
    newnode->next = temp->next;
    temp->next = newnode;
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
    if (temp == NULL) {
        cout << "Value not found" << endl;
        printlist();
        return;
    }
    temp->data = key;
    if(temp == tail){
        tail = temp;
    }
    printlist();
}

void Remove_head (){
    if(head == NULL){
        cout << "Underflow" << endl;
        printlist();
        return;
    }

    Node* temp = head; 
    head = head->next;
    delete temp;
    if(head == NULL){
        tail = NULL;
    }
    printlist();
}

void Remove_element(int key) {
    if (head == NULL) {
        cout << "Value not found" << endl;
        printlist();
        return;
    }

    if (head->data == key) {
        Remove_head();
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Value not found" << endl;
        printlist();
        return;
    }

    Node* delNode = temp->next;
    temp->next = delNode->next;

    if (delNode == tail)
        tail = temp;

    delete delNode;
    printlist();
}

void Remove_end() {
    if (head == NULL) {
        cout << "Underflow" << endl;
        printlist();
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = NULL;
        printlist();
        return;
    }

    Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }

    delete tail;
    tail = temp;
    tail->next = NULL;

    printlist();
}
int main(){

    int choice;
    while(cin >> choice && choice != 8){
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
    return 0;
}