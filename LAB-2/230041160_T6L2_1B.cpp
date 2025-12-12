#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

bool matching_brackets(char open, char close){
    return ((open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']'));
}

bool balanced_brackets(const string &n){
    stack<char>s;
    for(char c:n){
        if(c == '(' || c == '{' || c == '['){
            s.push(c);
        }
        else if(c == ')' || c == '}' || c == ']'){
            
                if(s.empty() || !matching_brackets(s.top(),c)){
                    return false;
                }
                s.pop();     
        }
    }
    return s.empty();
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    

    vector<string>values;
    int i=0;

    while(i < t){
        string n;
        getline(cin,n);

        if(!n.empty()){
            values.push_back(n);
            i++;
        }     
    }
    for(const string &n : values){
        if(balanced_brackets(n)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" <<  endl;
        }
    }
    return 0;
}