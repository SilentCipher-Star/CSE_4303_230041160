#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

struct TrieNode{

    TrieNode* left;  // bit 0
    TrieNode* right;  //bit 1

    TrieNode(){
        left = nullptr;
        right = nullptr;
    }

    ~TrieNode(){
        if(left) delete left;
        if(right) delete right;
    }
};

class Solution{

    TrieNode* root;

public:

    Solution(){
        root = new TrieNode;
    }

    ~Solution(){
        delete root;
    }

    void insert(int num){
        TrieNode* curr = root;
        for(int i = 31; i>= 0; i--){

            int bits = (num >> i) & 1;
            if(bits == 0){
                if(curr->left == nullptr){
                    curr->left = new TrieNode();
                }
                curr = curr->left;
            }else{
                if(curr->right == nullptr){
                    curr->right = new TrieNode();
                }
                curr = curr->right;
            }
        }
    }

    int findMaxXorNum(int num){    // ex-> 5
        TrieNode* curr = root;    // ex->3
        int currXor = 0;

        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1;  // extracting the bits

            int desireNum = 1-bit;

            if(desireNum == 0){
                if(curr->left != nullptr){
                    currXor += (1<<i);
                    curr = curr->left;
                }else{
                    curr = curr->right;
                }
            }else{
                if(curr->right != nullptr){
                    currXor += (1 << i);
                    curr = curr->right;
                }else{
                    curr = curr->left;
                }
            }
        }
        return currXor;
    }


int solve(vector<int>& num){
    if(num.size() < 2) return 0;

    for(int x : num){
        insert(x);
    }
    int globalMax = 0;
    for(int x : num){
        globalMax = max(globalMax, findMaxXorNum(x));
    }
    return globalMax;
}

};
int main(){

    string line;
    getline(cin,line);

    stringstream ss(line);
    int num;
    vector<int> nums;
    while (ss >> num){
        nums.push_back(num);
    }
    Solution solver;
    cout <<solver.solve(nums)  << endl;

    return 0;
} 