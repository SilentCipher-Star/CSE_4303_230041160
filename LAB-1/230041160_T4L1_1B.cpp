#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int>energy;
    int x;

    while(true){
        cin >> x;
        if(x == 0) break;

        energy.push_back(x);
    }

    int target;
    cin >> target;

    int count = 0;
    vector<pair<int,int>>worker_pairs;
    int n = energy.size();

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if((energy[i] + energy[j]) == target){
            
                count++;
                worker_pairs.push_back({i+1,j+1});

            }
        }
    }

    if(count == 0){
        cout << "No pair found!"<< endl;
    }
    else{           
        cout << count << " Pairs:" << endl;
        for(auto p : worker_pairs){
            cout << "(worker-" << p.first << ", worker-" << p.second << ')' << endl;
        }
    }
    return 0;
}