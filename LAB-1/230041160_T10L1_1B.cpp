#include<iostream>
#include<string>
using namespace std;

int main(){

    string secret, guess;
    cin >> secret >> guess;

    int freqs[10] = {0};
    int freqg[10] = {0};

    int n = secret.size();
    int bulls = 0, cows = 0;

    for(int i=0; i<n; i++){
        if(secret[i] == guess[i]){
            bulls++;
        }
        else{
            freqs[secret[i] - '0']++;
            freqg[secret[i] - '0']++;
        }
    }

    for(int i=0; i<10; i++){
        cows += min(freqg[i],freqs[i]);
    }

    cout << bulls << "B" << cows << "C";
    return 0;
}