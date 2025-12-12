#include<iostream>
using namespace std;

int front = -1, rear = -1, count = 0, capacity;
int arr[10000];

bool isEmpty(){
    return count == 0;
}

bool isFull(){
    return count == capacity;
}

void print_func(){
    if(isEmpty()){
        cout << "NULL" << endl;
        return;
    }
    for(int i = 0; i < count; i++){
        int index = (front + i) % capacity;
        cout << arr[index];
        if(i < count - 1) cout << " ";
    }
    cout << endl;
}

void push_front(int key){
    if(isFull()) return;

    if(isEmpty()){
        front = rear = 0;
    } else {
        front = (front + capacity - 1) % capacity;
    }
    arr[front] = key;
    count++;

    print_func();
}

void push_back(int key){
    if(isFull()) return;

    if(isEmpty()){
        front = rear = 0;
    } else {
        rear = (rear + 1) % capacity;
    }
    arr[rear] = key;
    count++;

    print_func();
}

void pop_front(){
    if(isEmpty()){
        cout << "NULL" << endl;
        return;
    }
    if(front == rear){
        front = rear = -1;
    } else {
        front = (front + 1) % capacity;
    }
    count--;
    print_func();
}

void pop_back(){
    if(isEmpty()){
        cout << "NULL" << endl;
        return;
    }
    if(front == rear){
        front = rear = -1;
    } else {
        rear = (rear + capacity - 1) % capacity;
    }
    count--;
    print_func();
}

int main(){
    cin >> capacity;

    int n, x;
    while(true){
        cin >> n;
        if(n == 6) break;

        switch(n){
            case 1: 
                cin >> x;
                push_front(x);
                break;

            case 2:  
                cin >> x;
                push_back(x);
                break;

            case 3: 
                pop_front();
                break;

            case 4:  
                pop_back();
                break;

            case 5: 
                cout << count << endl;
                break;
        }
    }
    return 0;
}
