#include<iostream>
#include<set>
#include<string>
using namespace std;

void solution(){

    string morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    int n;
    if(!(cin >> n)) return;

    set<string> uniqueness; // to store only unique elements and keep them sorted
    for(int i=0; i<n; i++){
        string word;
        cin >> word;

        string curr_morse = "";

        for(char c: word){
            int idx = c - 'a';
            curr_morse += morse[idx];
        }

        uniqueness.insert(curr_morse); // If same Morse appears again ,it won’t be added.
    }

    cout << uniqueness.size() << endl;
    for(string s: uniqueness){
        cout << s << endl;
    }
}
int main(){
    solution();
    return 0;
}
