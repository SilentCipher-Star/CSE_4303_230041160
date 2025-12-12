#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;
int count = 0;

void printDeque(){
    if(head == NULL){
        cout << "Empty" << endl;
        return;
    }

    Node* temp = head;
    while(temp != NULL){
        cout << temp->data;
        if(temp->next != NULL) cout << " ";
        temp = temp->next;
    }
    cout << endl;
}

void push_front(int key){
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
    count++;
    printDeque();
}

void push_back(int key) {
    Node* newnode = new Node();
    newnode->data = key;
    newnode->next = NULL;
    newnode->prev = tail;

    if (tail != NULL)
        tail->next = newnode;
    tail = newnode;

    if (head == NULL)
        head = newnode;

    count++;
    printDeque();
}

int pop_front(){
    if(head == NULL){
        cout << "Underflow" << endl;
        printDeque();
        return -1;
    }
    Node* temp = head;
    int val = temp->data;

    head = head->next;
    if(head != NULL){
        head->prev = NULL;
    }else{
        tail = NULL;
    }
    delete temp;
    count--;
    printDeque();   
    return val;
} 

int pop_back(){
    if(tail == NULL){
        cout << "Underflow" << endl;
        printDeque();
        return -1;
    }
    Node* temp = tail;
    int val = temp->data;

    tail = tail->prev;
    if(tail != NULL){
        tail->next = NULL;
    }else{
        head = NULL;
    }
    delete temp;
    count--;
    printDeque();
    return val;
}   

int size(){
    cout << count << endl;  
    return count;
}

int main() {
    int choice;
    while (cin >> choice && choice != 6) {
        if (choice == 1) {
            int x; cin >> x;
            push_front(x);
        }
        else if (choice == 2) {
            int x; cin >> x;
            push_back(x);
        }
        else if (choice == 3) {
            pop_front();
        }
        else if (choice == 4) {
            pop_back();
        }
        else if (choice == 5) {
            size();
        }
    }

    cout << "Exit" << endl;
    return 0;
}