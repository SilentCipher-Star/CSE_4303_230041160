#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;

struct TrieNode
{

    bool endmark;
    TrieNode *next[26];

    TrieNode()
    {
        endmark = false;
        for (int i = 0; i < 26; i++)
        {
            next[i] = nullptr;
        }
    }
} *root;

void insert(string str){

    TrieNode* curr = root;
    for(int i=0; i< str.length(); i++){
        int idx = str[i] - 'a';
        if(curr->next[idx] == nullptr){
            curr->next[idx] = new TrieNode();
        }
        curr = curr->next[idx];
    }
    curr->endmark = 1;
}

void dfs(TrieNode *curr, string wordsofar, vector<string>&suggestion){

    if(suggestion.size() == 3){
        return;
    }

    if(curr->endmark){
        suggestion.push_back(wordsofar);
    }

    for(int i =0; i<26; i++){
        if(curr->next[i] != nullptr){
            char ch = i + 'a';
            dfs(curr->next[i], wordsofar+ch,suggestion);
            if(suggestion.size() == 3) return;
        }
    }
}

void getSuggestions(string searchword){

    TrieNode* curr = root;
    bool pathbroken = false;
    string prefix = "";

    for(char c : searchword){
        c = tolower(c);
        prefix += c;
        int idx = c - 'a';

        if(pathbroken || curr->next[idx] == nullptr){
            pathbroken = true;
            cout << "Null" << endl;
        }
        else{
            curr = curr->next[idx];
            vector<string>suggestion;
            dfs(curr, prefix, suggestion);

            for(const string &s : suggestion){
                cout << s << " ";
            }
            cout << endl;
        }
    }
}
int main(){

    root = new TrieNode();
    string line, word;
    getline(cin, line);
    
    stringstream ss(line);
    while(ss >> word){
        insert(word);
    }

    string searchword;
    cin >> searchword;
    getSuggestions(searchword);

    return 0;
}