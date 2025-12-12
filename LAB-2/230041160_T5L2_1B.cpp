#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){

    int n;
    cin >> n;
    cin.ignore();
    
    for(int i=0; i<n; i++){
        string s;
        getline(cin, s);

        stack<char>st;

        for(char c: s){
            st.push(c);
        }

        while(!st.empty()){
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }
    return 0;
}