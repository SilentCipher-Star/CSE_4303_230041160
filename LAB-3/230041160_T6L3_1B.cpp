#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    string s;
    
   
    while (getline(cin, s)) {

        list<string> text;
        auto cursor = text.begin(); 
        string current = "";

        for (char c : s) {

            if (c == '[') {  
               
                if (!current.empty()) {
                    text.insert(cursor, current);
                    current = "";
                }
                cursor = text.begin(); 
            }
            else if (c == ']') {
              
                if (!current.empty()) {
                    text.insert(cursor, current);
                    current = "";
                }
                cursor = text.end(); 
            }
            else {
                current += c; 
            }
        }

  
        if (!current.empty()) {
            text.insert(cursor, current);
        }

       
        for (auto &part : text) {
            cout << part;
        }
        cout << endl;
    }

    return 0;
}
