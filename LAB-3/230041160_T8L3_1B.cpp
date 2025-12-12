#include <bits/stdc++.h>
using namespace std;

void rotateOnce(deque<int>& dq) {
    int x = dq.front();
    dq.pop_front();
    dq.push_back(x);
}

int main() {
    int N;
    while (cin >> N) {

        deque<int> dq;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            dq.push_back(x);
        }

        string player;
        cin >> player;

        string current = player;

        while (dq.size() > 1) {

          
            if (current == "Daiyan") {
                rotateOnce(dq);    
                dq.pop_front();     
            }
            else { 
                rotateOnce(dq);   
                rotateOnce(dq);    
                dq.pop_front();      
            }

            
            cout << current << " ";
            for (int x : dq) cout << x << " ";
            cout << "\n";

            
            if (current == "Daiyan") current = "Ishraq";
            else current = "Daiyan";
        }

        
        if (!cin.eof()) cout << "\n";
    }

    return 0;
}
