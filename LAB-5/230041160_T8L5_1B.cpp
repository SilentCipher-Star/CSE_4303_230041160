#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = NULL;
Node* ODD_EVEN(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* odd = head;
    Node* even = head->next;
    Node* evenlist = even;

    while(even != NULL && even->next != NULL){
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenlist;
    return head;
}

void print_list(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void insert(Node* &head, int x){
    Node* newnode = new Node();
    newnode->data = x;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newnode;

}

int main(){

    int x;
    while(cin >> x && x != -1){
        insert(head, x);
    }
    head = ODD_EVEN(head);
    print_list(head);
    return 0;
}