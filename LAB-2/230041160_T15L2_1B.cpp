#include<iostream>
using namespace std;

int main(){
    int capacity;
    cin >> capacity;

    cin.ignore();
    int top = -1, arr[10000] ;

    while(true){
        char ch;
        cin >> ch;
        if(ch == '/'){
            break;
        }
        if(ch == '+'){
            int val;
            cin >> val;

            if(top == capacity-1){
                cout << "Overflow !!!" << endl;
            }else{
                top ++;
                arr[top] = val;
            }

            cout << "Size :"<< (top+1)<<endl;
            cout << "Stack elements :";
            for(int i=0; i<=top; i++){
                cout << arr[i];
                if(i < top) cout << " ";
            }
            cout << endl;
            cout << "Top Element :"<< (top == -1 ? 0 : arr[top]) << endl;
            cout << "isFull :" << ((top == capacity-1) ? "True" : "False") << endl;

            cout << "isEmpty  :"<< (top == -1 ? "True" : "False") << endl;

        }else if(ch == '-'){
            // if(top == -1){
                
            // }else{
            //     top--;
            // }
            if(top != -1){
                top--;
            }
            cout << "Size :"<< (top+1)<<endl;
            cout << "Stack elements :";
            for(int i=0; i<top; i++){
                cout << arr[i];
                if(i < top) cout << " ";
            }
            cout << endl;
            cout << "Top Element :"<< (top == -1 ? 0 : arr[top]) << endl;
            cout << "isFull :" << ((top == capacity-1) ? "True" : "False") << endl;

            cout << "isEmpty  :"<< (top == -1 ? "True" : "False") << endl;
        }
    }
    return 0;
}