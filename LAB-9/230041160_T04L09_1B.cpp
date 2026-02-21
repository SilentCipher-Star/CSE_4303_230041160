#include<iostream>
#include<string>
using namespace std;

struct TrieNode{
    
    bool endmark;
    int count;
    TrieNode *next[26];

    TrieNode()
    {
        endmark = false;
        count = 0;
        for (int i = 0; i < 26; i++)
        {
            next[i] = nullptr;
        }
    }
} *root;

void toLowercase(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

bool search(string str)
{
    TrieNode *curr = root;
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        int idx = str[i] - 'a';
        if (curr->next[idx] == nullptr)
        {
            return false;
        }
        curr = curr->next[idx];
        }
    return curr->endmark;
}

void insert(string str)
{
    TrieNode *curr = root;
    if(search(str)) return;

    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        int idx = str[i] - 'a';

        if (curr->next[idx] == nullptr)
        {
            curr->next[idx] = new TrieNode();
        }
        curr = curr->next[idx];
        curr->count++;
    }
    curr->endmark = 1;
}

int prefixCount(string& str){

    TrieNode* curr = root;
    for(int i=0; i<str.length(); i++){
        int idx = str[i] - 'a';
        if(curr->next[idx] == nullptr){
            return 0;
        }
        curr = curr->next[idx];
    }
    return curr->count;
}

void DeleteTri(TrieNode* curr){  // to properly free every byte of memory allocated in the 
    
    if(curr == nullptr) return;

    for(int i=0; i<26; i++){
        if(curr->next[i]){
            DeleteTri(curr->next[i]);
        
        }
        delete curr;
    }
}
int main(){

    root = new TrieNode();
    int n,q;
    cin >> n >> q;

    string word;
    for(int i=0; i<n; i++){
        cin >> word;
        toLowercase(word);
        insert(word);
    }

    for(int i=0; i<q; i++){
        cin >> word;
        toLowercase(word);
        cout<< prefixCount(word) << endl;
    }
    DeleteTri(root);
    return 0;
}