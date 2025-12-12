#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> students;
    stack<int> dishes;

    string temp;

   
    cin >> temp; 
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        students.push(x);
    }

   
    cin >> temp; 
    int dishList[10000];
    for (int i = 0; i < N; i++) {
        cin >> dishList[i];
    }

    
    for (int i = N - 1; i >= 0; i--) {
        dishes.push(dishList[i]);
    }

    int rotateCount = 0;

   
    while (!students.empty() && !dishes.empty()) {
        if (students.front() == dishes.top()) {
          
            students.pop();
            dishes.pop();
            rotateCount = 0; 
        }
        else {
           
            int x = students.front();
            students.pop();
            students.push(x);

            rotateCount++;

            
            if (rotateCount == students.size()) {
                break;
            }
        }
    }

    cout << students.size() << endl;
    return 0;
}
