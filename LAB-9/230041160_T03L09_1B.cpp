#include<iostream>
#include<string>
#include<sstream>
using namespace std;

struct TrieNode{

    bool endmark;
    TrieNode* next[26];

    TrieNode(){
        endmark = false;
        for(int i=0; i<26; i++){
            next[i] = nullptr;
        }
    }
} * root;

void insert(string str){
    TrieNode* curr = root;

    int len = str.length();
    for(int i=0; i<len; i++){
        int idx = str[i] - 'a';

        if(curr->next[idx] == nullptr){
            curr->next[idx] = new TrieNode();
        }
        curr = curr->next[idx];
    }
    curr->endmark = 1;
}

bool search(string str){
    TrieNode* curr = root;
    int len =  str.length();
    for(int i=0; i<len; i++){
        int idx = str[i] - 'a';
        if(curr->next[idx] == nullptr){
            return false;
        }
        curr = curr->next[idx];
    }
    return curr->endmark;
}

void displayrecursion(TrieNode *curr, string &str){
    if(curr->endmark){
        cout << str << endl;
    }
    for(int i=0; i<26; i++){
        if(curr->next[i] != nullptr){
            char ch = i + 'a'; //converts index i back to character
            str.push_back(ch);  //inserts each and every found character inside str
            displayrecursion(curr->next[i],str); //after finding a character, we call the fucntion again to move our curr pointer down to that child
            str.pop_back(); // backtracks(tries to remove the already found word while trying to look for other characters if their door is open)
        }
    }
}

void display(){
    string str = "";
    displayrecursion(root,str);
}

int main(){
    root = new TrieNode();

    string line;
    getline(cin,line);
    
    stringstream ss(line); //tp break the line into individual word
    string word;

    while(ss >> word){
        insert(word);
    }

    display();
    cout << endl;

    getline(cin, line);
    stringstream ss2(line);

    while(ss2>> word){
        if(search(word)){
            cout <<"T" << " ";
        }
        else{
            cout << "F" << " ";
        }
    }
    return 0;
}