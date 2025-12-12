#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    int n,r;
    cin >> n >> r;

    long long A[100000];
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    sort(A,A+n);

    long long pre[100000];
    pre[0] = A[0];
    for(int i=1; i<n; i++){
        pre[i] = pre[i-1] + A[i];
    }

    while(r--){
        long long p;
        cin >> p;

        int lo = 0, hi = n-1, ans = -1;
        while(lo <= hi){
            int mid = (lo+hi)/2;

            if(A[mid] <= p){
                lo = mid+1;
                ans = mid;
            }
            else{
                hi = mid-1;
            }
        }
        if(ans == -1){
            cout << 0 << " " << 0 << endl;
        }
        else{
            cout << (ans+1) << " " << pre[ans]<< endl;
        }
    }
    return 0;
}