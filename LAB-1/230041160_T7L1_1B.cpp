#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int main(){

    string n;
    cin >> n;
    vector<int>v;

    for(char c: n){
        if(c != '+'){
            v.push_back(c - '0');
        }
    }
    sort(v.begin(),v.end());

    for(int i=0; i <v.size(); i++){
        if(i > 0) cout << '+';
        cout << v[i];
    }
    return 0;
}