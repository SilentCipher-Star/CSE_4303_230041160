#include<iostream>
using namespace std;

int capacity;
int front = 0;
int rear = -1;
int count = 0;
int arr[100000];

bool isEmpty(){
    return count == 0;
}
bool isFull(){
    return count == capacity;
}

void print_queue(){
    if(isEmpty()) return;

    for(int i = 0; i<count; i++){
        int index = (front+i)%capacity;
        cout << arr[index];
        if(i < count-1) cout << " ";
    }
    cout << endl;
}

void Enqueue(int x){
    if(isFull()){
        cout << "Overflow" << endl;
        return;
    }
    rear = (rear+1)%capacity;
    arr[rear] = x;
    count++;

    print_queue();
}

void Dequeue(){
    if(isEmpty()){
        cout << "Underflow"<< endl;
        return;
    }
    front = (front+1) % capacity;
    count--;
    print_queue();
}

int size(){
    return count;
}
void Front(){
    cout << arr[front]<< endl;
}
int main(){

    cin >> capacity;
    int n;

    while(true){
        cin >> n;
        if(n == -1) break;

        switch(n){
            case 1:{
                int x;
                cin >> x;
                cout << "Enqueue: ";
                Enqueue(x);
                break;
            }
            case 2:{
                cout << "Dequeue ";
                Dequeue();
                break;
            }
            case 3:{
                cout <<"isEmpty:" <<(isEmpty() ? "True" : "False") << endl;
                break;
            }
            case 4:{
                cout <<"isFull:" <<(isFull() ? "True" : "False") << endl; 
                break;
            }
            case 5:{
                cout << "size:" <<size() << endl;
                break;
            }
            case 6:{
                cout << "Front:";
                Front();
                break;
            }
        }
    }
    cout << "Exit" << endl;
    return 0;
}