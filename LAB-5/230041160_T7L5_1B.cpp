#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Queue{

private:
    Node* front_node;
    Node* rear_node;
    int curr_size;
    int max_size;

public:
    Queue(int n){
        front_node = NULL;
        rear_node = NULL;
        curr_size = 0;
        max_size = n;
    }

    bool isFull(){
        return curr_size == max_size;
    }

    bool isEmpty(){
        return curr_size == 0;
    }

    void size(){
        cout << curr_size<< endl;
    }

    void front(){
        if(isEmpty()){
            cout << "Front: Underflow" << endl;
        }
        else{
            cout << "Front: "  << front_node->data << endl;
        }
    }

    void print_queue(string queue){
        cout << queue << ":";
        Node* temp = front_node;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void Enqueue(int x){
        if(isFull()){
            cout << "Enqueue: OverFlow" << endl;
            return;
        }
        Node* newnode = new Node();
        newnode->data = x;
        newnode->next = NULL;
        if(isEmpty()){
            front_node = rear_node = newnode;
        }
        else{
            rear_node->next = newnode;
            rear_node = newnode;
        }
        curr_size++;
        print_queue("Enqueue");
    }

    void Dequeue(){
        if(isEmpty()){
            cout << "Dequeue:UnderFlow" << endl;
            return;
        }
        Node* temp = front_node;
        front_node = temp->next;
        delete temp;

        if(front_node == NULL){
            rear_node = NULL;
        }
        curr_size--;
        print_queue("Dequeue");
    }

};
int main(){

    int n;
    cin >> n;

    Queue q(n);

    int id;
    while(cin >> id && id != -1){
        if(id == 1){
            int x;
            cin >> x;
            q.Enqueue(x);
        }
        else if(id == 2){
            q.Dequeue();
        }
        else if(id == 3){
            cout<< "isEmpty: " << (q.isEmpty() ? "True" : "False");
        }
        else if(id == 4){
            cout<< "isFull: " << (q.isFull() ? "True" : "False");
        }
        else if(id == 5){
            q.size();
        }
        else if(id == 6){
            q.front();
        }
    }
    cout << "Exit" << endl;
    return 0;
}