#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int t;
        if (!(cin >> t)) return 0; 
        
        unordered_map<int,int> groupOf;
        for (int g = 1; g <= t; ++g) {
            int cnt;
            cin >> cnt;
            for (int i = 0; i < cnt; ++i) {
                int person;
                cin >> person;
                groupOf[person] = g;
            }
        }

        
        vector<queue<int>> groupMembers(t + 1);
        queue<int> groupQueue;          
        vector<bool> inQueue(t + 1, false);

       
        string line;
        getline(cin, line);

   
        while (true) {
            if (!getline(cin, line)) break; 

           
            if (line.find_first_not_of(" \t\r\n") == string::npos) continue;

           
            istringstream iss(line);
            string cmd;
            iss >> cmd;

            if (cmd == "STOP") {
                break;
            }
            else if (cmd == "ENQUEUE") {
                int x;
                if (!(iss >> x)) {
                
                    continue;
                }
                int g = groupOf[x]; 
                if (!inQueue[g]) {
                    groupQueue.push(g);
                    inQueue[g] = true;
                }
                groupMembers[g].push(x);
            }
            else if (cmd == "DEQUEUE") {
                if (!groupQueue.empty()) {
                    int g = groupQueue.front();
                   
                    if (!groupMembers[g].empty()) {
                        groupMembers[g].pop();
                        if (groupMembers[g].empty()) {
                            groupQueue.pop();
                            inQueue[g] = false;
                        }
                    } else {
                       
                        groupQueue.pop();
                        inQueue[g] = false;
                    }
                }
                
            }
            else {
                
                continue;
            }
        } 

        vector<int> output; 
        queue<int> tempGroupQueue = groupQueue;

        while (!tempGroupQueue.empty()) {
            int g = tempGroupQueue.front();
            tempGroupQueue.pop();

          
            queue<int> copyMembers = groupMembers[g];
            while (!copyMembers.empty()) {
                output.push_back(copyMembers.front());
                copyMembers.pop();
            }
        }

       
        for (size_t i = 0; i < output.size(); ++i) {
            cout << output[i];
            if (i + 1 < output.size()) cout << ", ";
        }
        cout << "\n";

       
    }

    return 0;
}
