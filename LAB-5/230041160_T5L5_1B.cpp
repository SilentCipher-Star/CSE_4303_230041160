#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head1 = NULL;
Node* tail1 = NULL;

Node* head2 = NULL;
Node* tail2 = NULL;

Node* head3 = NULL;
Node* tail3 = NULL;

void insert_back(Node*& head, Node*& tail, int key){
    Node* newnode = new Node();
    newnode->data = key;
    newnode->next = NULL;
    if(head == NULL){
        head = tail = newnode;
    }
    else{
        tail->next = newnode;
        tail = newnode;
    }

}

void readlist(Node* &head, Node* &tail){
    int x;
    while(cin >> x && x != -1){
        insert_back(head, tail,x);
    }
}

void intersection(){
    Node* p1 = head1;
    Node* p2 = head2;

    while(p1 != NULL && p2 != NULL){
        if(p1->data == p2->data){
            insert_back(head3,tail3,p1->data);
            p1 = p1->next;
            p2 = p2->next;

        }
        else if(p1->data < p2->data){
            p1 = p1->next;
        }
        else{
            p2 = p2->next;
        }
    }
}
void print_list(Node* head){
    if(head == NULL){
        cout << "Empty"<< endl;
        return;
    }

    while(head != NULL){
        cout << head->data ;
        if(head != NULL) cout << " ";
        head = head->next;
    }
}

int main(){

    readlist(head1,tail1);
    readlist(head2,tail2);

    intersection();
    print_list(head3);

    return 0;
}