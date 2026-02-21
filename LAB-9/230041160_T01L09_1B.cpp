#include<iostream>
#include<vector>
using namespace std;

int hashFunction(int key, int tablesize){
    return key%tablesize;
}

// f(i)=i*hash2(x); hash2(x) = R - (x % R) with R=7
int hash2(int x){
    int R = 7;
    return R-(x%R);
}

int main(){

    int choice ,N,Q;
    cin >> choice >> N >> Q;

    vector<int>hashTable(N,-1);
    int insertedCOunt = 0;

    for(int q=0; q<Q; q++){
        int key;
        cin >> key;

        bool inserted = false;
        int attempt = 0;

        while(attempt < 6 && !inserted){
            int index;
            int h = hashFunction(key,N);

            if(choice == 1){
                //Linear prob
                index = (h+attempt)%N;
            }
            else if(choice == 2){
                //quadratic prob
                index = (h + attempt*attempt)%N;
            }
            else if(choice == 3){
                //double hashing
                index = (h+attempt*hash2(key))%N;
            }

            if(hashTable[index] == -1){
                hashTable[index] = key;
                insertedCOunt++;
                cout << "Inserted : Index-" << index << "(L.F=" << (double)insertedCOunt/N << ")" << endl; 
                inserted = true;
            }
            else{
                cout << "Collision: Index-" << index << endl;
            }
            attempt++;
        }

        if(!inserted){
            cout << "Input Abandoned" << endl;
        }
    }
    return 0;
}
