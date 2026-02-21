#include<iostream>
#include<map>
#include<string>
#include<sstream>
using namespace std;

void solution(){
    string line;
    while(getline(cin, line)){

        
        for(int i=0; i<line.length(); i++){
            if(ispunct(line[i])){
                line[i] = ' ';
            }
        }
        stringstream ss(line);   //extracting the words one by one
        string word;
        
        map<string, int>freq;
        while(ss >> word){
            freq[word]++;
        }
        
        for(auto pair : freq){
        
            string words = pair.first;
            int count = pair.second;
            if(count > 1){
                cout << words << " " << count << endl;
            }
        }
    }
}
int main(){
    solution();
    return 0;
}