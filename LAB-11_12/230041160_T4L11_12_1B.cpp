#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main(){

    int n;
    while(!(cin >> n)) return 0;
    vector<int>arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int max_j = log2(n);
    vector<vector<int>>s(n,vector<int>(max_j+1));

    for(int i=0; i<n; i++){
        s[i][0] = arr[i];
    }

    for(int j=1; j<=max_j; j++){
        for(int i=0; i+(1<<j)-1 <n; i++){
            s[i][j] = s[i][j-1] | s[i+(1<<(j-1))][j-1];
        }
    }

    int q;
    cin >> q;

    for(int i=0; i<q; i++){
        int L,R,target_idx;
        cin >> L >> R >> target_idx;

        int len = R-L+1;
        int j = log2(len);

        int left_block_start = L;
        int right_block_start = R -(1 << j) +1;

        int range_or = s[left_block_start][j] | s[right_block_start][j];

        if(range_or == arr[target_idx]){
            cout <<"YES\n";
        }else{
            cout <<"NO\n";
        }
    }
    return 0;
}