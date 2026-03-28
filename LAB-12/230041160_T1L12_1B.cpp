#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){

    string s;
    cin >> s;

    int q;
    cin >> q;

    int n = s.length();
    vector<vector<int>>prefix(n+1,vector<int>(26,0));

    for(int i=1; i<=n; i++){
        for(int j=0; j<26; j++){
            prefix[i][j] = prefix[i-1][j];  //copying char count from prev idx
        }
        char curr = s[i-1];  
        prefix[i][curr - 'a']++;    //increasinf cnt of curr char at pos i
    }

    while(q--){
        int l,r;
        cin >> l >> r;

        int maxfrq = 0;
        char ans = 'a';
        for(int i=0; i<26; i++){
            int frq = prefix[r][i] - prefix[l-1][i];
            if(frq > maxfrq){
                maxfrq = frq;
                ans = char('a'+ i);
            }
        }
        cout << ans << ":" << maxfrq << endl;
    }
    return 0;
}