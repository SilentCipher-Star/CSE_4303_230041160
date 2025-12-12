#include<iostream>
using namespace std;
int main(){

    int n;
    int freq[10] = {0};

    while(true){
        cin >> n;
        if(n <= 0) break;
        if(n >=1 && n <=9) freq[n]++;
    }

    bool printed[10] = {false};

    while(true){
        int num = -1;
        int Max = 0;
        for(int i=1; i<= 9; i++){
            if(!printed[i] && freq[i] > Max){
                Max = freq[i];
                num = i;
            }

        }
        if(num == -1 || Max == 0)break;
        cout<< num << " occurs " << Max << " time";
        if(Max > 1) cout << 's';
        cout << endl;
        
        printed[num] = true;

    }
    return 0;
}