#include<iostream>
#include<string>
#include<vector>

using namespace std;
int main(){

    int length;
    cin >> length;

    string music;
    cin >> music;

    vector<string>original;
    string word = "";
    int i=0, n = music.size();

    while(i < n){
        if(i+2 < n && music[i] == 'd' && music[i+1] == 'u' && music[i+2] == 'b'){
            if(!word.empty()){
                original.push_back(word);
                word ="";
            }
            i+=3;
        }
        else{
            word += music[i];
            i++;
        }
    }

    if(!word.empty()){
        original.push_back(word);
    }

    int m = original.size();
    for(int i=0; i<m; i++){
        if(i) cout << " ";
        cout << original[i];
    }
    return 0;
}