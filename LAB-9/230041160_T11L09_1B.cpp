#include<iostream>
#include<string>
#include<set>
#include<sstream>
using namespace std;


string getHash(string word){
    set<char>uniquechar;

    for(char c: word){
        uniquechar.insert(c);
    }

    string signature = "";
    for(char c : uniquechar){
        signature += c;
    }
    return signature; // uniquely represents the character set of the word.
}

void solve(){

    string sentence, target;
    if(!getline(cin,sentence)) return;
    if(!(cin >> target)) return;

    string targetHash = getHash(target);
    stringstream ss(sentence); // Allows word-by-word extraction.

    string currword;
    while(ss >> currword){
        if(getHash(currword) == targetHash){
            cout << currword << " ";
        }
    }
    cout << endl;
}
int main(){

    solve();
    return 0;
}