#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

string parenthesis(const vector<string>& val) {
    stack<char> st;
    

    string code = "";
    for (const string& line : val) {
        code += line;
    }
    
    for (char c : code) {
 
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
     
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) {
                return "Error"; 
            }
            
            char top = st.top();
            st.pop();
            
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return "Error";  
            }
        }
    }
    
 
    if (!st.empty()) {
        return "Error";
    }
    
    return "No Errors";
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    vector<string> val;
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        val.push_back(line);
    }
    
    cout << parenthesis(val) << endl;
    
    return 0;
}
