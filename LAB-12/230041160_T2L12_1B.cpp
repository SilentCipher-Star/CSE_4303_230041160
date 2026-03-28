#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int query(int l,int r, vector<vector<int>>&sparse){
    int win = r-l+1;     //size of the query
    int j = log2(win);   //choosing the largest block size fitting in this range
    
    int left = sparse[l][j];   //first block
    int right = sparse[r-(1<<j)+1][j];   //second block

    int ans = min(left, right);
    cout << "Min=" << ans << " ";
    cout << "min([" << l << "," << l + (1 << j) - 1 << "],";
    cout << "[" << r - (1 << j) + 1 << "," << r << "])";

    return ans;
}

int main(){

    int n;
    cin >> n;

    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int q;
    cin >> q;

    int k = log2(n)+1;
    vector<vector<int>>sparse(n, vector<int>(k));
    
    cout << "Ranges to be stored in Sparse Table:" << endl;

    for(int i=0; i<n; i++){
        sparse[i][0] = arr[i];
        cout << '(' << i << ',' << i << ')' ;
        for(int j=1; j<k; j++){
            if(i+ (1 << j) -1 < n){
                cout << " (" << i << ',' << i + (1 << j) - 1 << ')' ;
            }
        }
        cout << endl;
    }

    for (int j = 1; j < k; j++)
    {
        for (int i = 0; i + (1 << j) <= n; i++)
        {
            sparse[i][j] = min(
                sparse[i][j - 1],
                sparse[i + (1 << (j - 1))][j - 1]);
        }
    }

    
    cout << "\nStatus of Sparse Table:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (i + (1 << j) <= n)
                cout << sparse[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for(int i = 1; i<= q; i++){
        int l,r;
        cin >> l >> r;

        cout << "Query- " << i << ": ";
        query(l, r, sparse);
        cout << endl;
    }

    return 0;
}