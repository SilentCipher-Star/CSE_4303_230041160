#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int need = 1;
        stack<int> s;

        for(int i = 0; i < n; i++) {
            int x = a[i]; 

            if(x == need) {
                need++;
            } else {
                while(!s.empty() && s.top() == need) {
                    s.pop();
                    need++;
                }
                s.push(x);
            }
        }

   
        while(!s.empty() && s.top() == need) {
            s.pop();
            need++;
        }

        if(need == n + 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
