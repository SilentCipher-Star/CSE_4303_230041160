#include<iostream>
#include<vector>
#include <map>

using namespace std;
int main(){

    int n;
    vector<int>num1, num2;

    while(true){
        cin >> n;
        if(n < 0) break;
        num1.push_back(n);
    }

    while(true){
        cin >> n;
        if(n < 0) break;
        num2.push_back(n);
    }

    map<int,int> count1, count2;

    for(int n : num1) count1[n]++;
    for(int n : num2) count2[n]++;

    vector<int>result;

    for(auto &p:count1){
        int num = p.first;
        if(count2[num] > 0){
            int times = min(p.second, count2[num]);
            for(int i=0; i<times; i++){
                result.push_back(num);
            }
        }
    }
    for(int n: result){
        cout << n << " ";
    }
    return 0;
}