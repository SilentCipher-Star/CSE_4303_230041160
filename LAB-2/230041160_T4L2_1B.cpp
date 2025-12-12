#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){

    int num;
    vector<int>arr;
    while(true){
        cin >> num;
        if(num == -1) break;
        arr.push_back(num);
    }
    int n = arr.size();
    vector<int>NGE(n,-1);
    stack<int>st;

    for(int i=n-1; i>= 0; i--){
        while (!st.empty() && st.top() <= arr[i]) {
   
            st.pop();
        }
        if(!st.empty()){
            NGE[i] = st.top();
        }

        st.push(arr[i]);
    }

    for(int i=0; i<n; i++){
        cout << NGE[i];

        if(i != n-1){
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}