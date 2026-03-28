#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main(){
    int n,q;
    while(!(cin >> n >> q)) return 0;
    vector<int>arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<q; i++){
        int l,r;
        cin >> l >> r;

        l = l-1;
        r = r-1;

        int len = r-l+1;
        if((len%2) != 0){
            cout << "-1" << endl;
        }
        else{
            int count_1  = 0;
            for(int i=l; i<= r; i++){
                if(arr[i] == 1){
                    count_1++;
                }
            }
            int target = len/2;

            int flips  = abs(count_1 - target);
            cout << flips << endl;
        }
    }
    return 0;
}