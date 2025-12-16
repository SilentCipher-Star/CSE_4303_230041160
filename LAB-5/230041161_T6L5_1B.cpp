#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Stack{

private:
    Node* top_node;
    int curr_size;
    int max_size;

public:
    Stack(int n){
        top_node = NULL;
        curr_size = 0;
        max_size = n;
    }

    void print_stack(){
        if(isEmpty()){
            cout << "UnderFlow"<< endl;
            return;
        }
        int arr[100];
        int i=0;
        Node* temp = top_node;

        while(temp != NULL){
            arr[i++] = temp->data;
            temp = temp->next;
        }

        for(int j = i-1; j>= 0; j--){
            cout << arr[j] << " ";
        }
        cout << endl;
    }

    void push(int x){
        if(isFull()){
            cout << "OverFlow" << endl;
            return;
        }

        Node* newnode = new Node();
        newnode->data = x;
        newnode->next = top_node;
        top_node = newnode;
        curr_size++;

        print_stack();
    }

    void pop(){
        if(isEmpty()){
            cout << "UnderFlow" << endl;
            return;
        }

        Node* temp = top_node;
        top_node = temp->next;
        delete temp;
        curr_size--;

        print_stack();
    }

    bool isFull(){
        return (curr_size == max_size);
    }

    bool isEmpty(){
        return curr_size == 0;
    }

    int size(){
        return curr_size;
    }

    void top(){
        if(isEmpty()){
            cout << "UnderFlow" << endl;
            return;
        }else{
            cout << top_node->data << endl;
        }
    }

};
int main(){

    int n;
    cin >> n;

    Stack st(n);

    int id;
    while(cin >> id && id != -1){
        if(id == 1){
            int x;
            cin >> x;
            st.push(x);
        }
        else if(id == 2){
            st.pop();
        }
        else if( id == 3){
            cout << (st.isEmpty() ? "True" : "False");
        }
        else if(id == 4){
            cout << (st.isFull() ? "True" : "False");
        }
        else if(id == 5){
            st.size();
        }
        else if(id == 6){
            st.top();
        }
    }
    return 0;
}