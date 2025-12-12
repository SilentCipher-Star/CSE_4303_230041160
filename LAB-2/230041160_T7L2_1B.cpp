#include<iostream>
#include<stack>
#include<string>
using namespace std;

int post_func(const string &n){
    stack<int>s;

    for(char c:n){
        if(c >= '0' && c <= '9'){
            s.push(c - '0');
        }
        else{
            int x = s.top(); s.pop();
            int y = s.top();s.pop();
            int result = 0;

            switch(c){
                case '+': result = y+x; break;
                case '-': result = y-x; break;
                case '*': result = y*x; break;
                case '/': result = y/x; break;
            }
            s.push(result);
        }
    }
    return s.top();
}
int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    cin.ignore();
    for(int i=0; i<t; i++){
        string n;
        getline(cin,n);

        cout << post_func(n) << endl;
    }


    return 0;
}