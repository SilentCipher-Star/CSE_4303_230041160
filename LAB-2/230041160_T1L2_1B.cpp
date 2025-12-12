#include<iostream>
#include<stack>
using namespace std;

int top = -1, arr[100000], capacity;

bool isEmpty(){
    return top == -1;
}

bool isFull(){
    return top == capacity-1;
}

void printStack(){
    if(isEmpty()){
        return;
    }

    for(int i=0; i<=top; i++){
        cout << arr[i];
        if(i < top) cout << " ";
    }
    cout << endl;
}

void push(int n){
    if(isFull()){
        cout << "Overflow" << endl;
        return;
    }
    top++;
    arr[top] = n;
    printStack();

}
void pop(){
    if(isEmpty()){
        cout << "Underflow" << endl;
        return;
    }

    top--;
    if(top >= 0){
        printStack();
    }
}

int size(){
    return top+1;
}

void topElement(){
    if(isEmpty()) cout << "Stack is empty" << endl;
    else cout << arr[top]<< endl;
}

int main(){

    cin >> capacity;
    int n;
    
    while(true){
        cin >> n;
        if(n == -1) break;

        switch(n){
            case 1:
                int c;
                cin >> c;
                push(c);
                break;
            case 2:
                pop();
                break;
            case 3:
                cout << (isEmpty() ? "True" : "False") << endl;
                break;
            case 4:
                cout << (isFull() ? "True" : "False") << endl;
                break;
            case 5:
                cout << size() << endl;
                break;
            case 6:
                topElement();
                break;
        }
    }
    return 0;
}