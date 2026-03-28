#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){

    int N;
    while(!(cin >> N)) return 0;
    vector<int>arr(N);
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    int max_j = log2(N);
    vector<vector<int>>spares(N,vector<int>(max_j+1));

    for(int i=0; i<N; i++){  //gcd of single number is the number itself
        spares[i][0] = arr[i];  //initializing the base number 2^0
    }

    for(int j=1; j<= max_j ; j++){
        for(int i=0; i +(1 << j) <= N; i++){

            spares[i][j] = __gcd(spares[i][j-1], spares[i + (1 << (j-1))][j-1]);;
        }
    }

    cout << "Ranges to be stored in Sparse Table: \n";
    for(int i=0; i<N; i++){
        for(int j=0; j<= max_j ; j++){
            if(i +(1<<j)-1 < N){
                cout << "(" << i << ',' << i+(1<<j)-1 << ") ";
            }
        }
        cout <<"\n";
    }
    cout << "\n";

    cout << "Status of Sparse Table:\n";
     for(int i=0; i<N; i++){
        for(int j=0; j<= max_j ; j++){
            if(i +(1<<j)-1 < N){
                cout << spares[i][j] << " ";
            }
        }
        cout <<"\n";
    }
    cout << "\n";


    int q;
    cin >> q;
    for(int i=1; i<=q; i++){
        int l,r;
        cin >> l >>r;

        int len = r-l+1;
        int j = log2(len);

        int left_block_start = l;
        int left_block_end = l+(1<<j)-1;

        int right_block_start = r-(1<<j)+1;
        int right_block_end = r;

        int ans = __gcd(spares[left_block_start][j],spares[right_block_start][j]);

        cout << "Query-" << ": " << "GCD=" << ans << " gcd([" << left_block_start << "," << left_block_end << "],[" << right_block_start << "," << right_block_end << "])" << endl;
    }
    return 0;
}