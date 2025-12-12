#include<iostream>
#include<vector>
using namespace std;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<int>pos;

    while(true){
        cin >> n;
        if(n == -1) break;
        pos.push_back(n);
    }

    int size = pos.size();
    vector<double>values(size);

    for(int i=0; i<size; i++){
        cin >> values[i];
    }
    vector<double>ans(size);

    for(int i=0; i<size; i++){
        int p = pos[i];
        ans[p-1] = values[i];
    }

    for(int i=0; i<size; i++){
        cout << ans[i] << " ";
    }

    return 0;
}