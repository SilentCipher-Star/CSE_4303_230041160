#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    vector<int>num;
    int n;
    int target;
    while (cin >> n && n != -1){
        num.push_back(n);
    }
    cin >> target;

    unordered_map<int,int>freq; //number of times each number appeared
    vector<pair<int,int>>result; // to store the pairs

    for(int x : num){
        freq[x]++;
    }
    
    for(int x: num){
        int complement = target - x;
        if(freq[x] > 0 && freq[complement] > 0){
            if(x == complement && freq[x] > 2){
                continue;
            }
            result.push_back({x,complement});
            freq[x]--;
            freq[complement]--;
        }
    }
    if(result.empty()){
        cout << "No pairs found" << endl;
    }else{
        for(size_t i=0; i< result.size(); i++){
            cout << "(" << result[i].first << "," << result[i].second << ")";
            if(i < result.size()-1){
                cout <<",";
            }
        }
    }

    return 0;
}