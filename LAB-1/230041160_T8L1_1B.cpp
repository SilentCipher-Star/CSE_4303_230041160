#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int count_inversions(const string &s){
    int inversion = 0;
    int n = s.size();
    
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(s[i] > s[j]){
                inversion++;
            }
        }
    }
    return inversion;
}

int main(){
    int length, n;
    cin >> length >> n;

    vector<pair<string, int>> sequences;
    
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int inverse = count_inversions(s);
        sequences.push_back({s, inverse});
    }

    
    sort(sequences.begin(), sequences.end(),
         [](const pair<string,int>& a, const pair<string,int>& b){
             return a.second < b.second;
         });

    
    for(auto &p: sequences){
        cout << p.first << " " << p.second << endl; 
    }

    return 0;
}
