#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* head = NULL;
Node* tail = NULL;

void insert_back(int key){
    Node* newnode = new Node();
    newnode->data = key;
    newnode->next = NULL;
    if(head == NULL){
        head = tail = newnode;
    }else{
        tail->next = newnode;
        tail = newnode;
    }
}

void No_duplicates(){
    Node *current = head;
    while(current != NULL && current->next != NULL){
        if(current->data == current->next->data){
            Node* duplicate = current->next;
            current->next = duplicate->next;
            delete duplicate;
        }else{
            current = current->next;
        }
    }
}

void print_list(){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){

    int x;
    while(cin >> x && x != -1){
        insert_back(x);
    }

    No_duplicates();
    print_list();
    return 0;
}