#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q; 

    stack<int> s1, s2; 

    while (q--) {
        int type, x;
        cin >> type;

        if (type == 1) { 
            cin >> x;

            if ((s1.size() + s2.size()) >= n) {
                cout << "Size:" << n << " Elements: Overflow!" << endl;
                continue;
            }

            s1.push(x);
        }
        else if (type == 2) { 
            if (s1.empty() && s2.empty()) {
                cout << "Size:0 Elements: Null" << endl;
                continue;
            }

           
            if (s2.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }

            s2.pop(); 
        }

       
        int size = s1.size() + s2.size();
        cout << "Size:" << size << " Elements:";

        if (size == 0) {
            cout << " Null";
        } else {
          
            vector<int> temp_s2;
            stack<int> copy_s2 = s2;
            while (!copy_s2.empty()) {
                temp_s2.push_back(copy_s2.top());
                copy_s2.pop();
            }
            for (int i = temp_s2.size() - 1; i >= 0; i--) {
                cout << " " << temp_s2[i];
            }

           
            vector<int> temp_s1;
            stack<int> copy_s1 = s1;
            while (!copy_s1.empty()) {
                temp_s1.push_back(copy_s1.top());
                copy_s1.pop();
            }
            for (int i = 0; i < temp_s1.size(); i++) {
                cout << " " << temp_s1[i];
            }
        }

        cout << endl;
    }

    return 0;
}
