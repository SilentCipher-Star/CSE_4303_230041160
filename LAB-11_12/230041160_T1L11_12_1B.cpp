#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

    int n,m;
    while(!(cin >> n >> m)) return 0;

    vector<int>height(n);
    for(int i=0; i<n; i++){
        cin >> height[i];
    }

    int success_catapult = 0;

    for(int q=0; q<m; q++){
        int A,B;
        cin >> A >> B;

        A = A-1;    //since the problem uses 1 based index
        B = B-1;

        bool can_catapult = true;

        int start_hill = min(A,B) +1;
        int end_hill = max(A, B) - 1;

        for(int i=start_hill; i<=end_hill; i++){   //looping through the hill betwn the range
            if(height[i] > height[A]){
                can_catapult = false;
                break;
            }
        }

        if(can_catapult){
            success_catapult++;
        }
    }

    cout << success_catapult << endl;

    return 0;
}
